#!/usr/bin/python
# -*- coding: utf-8 -*-

import sqlite3 as lite
import sys
import taglib
import os
import art

# find files, then append to array
array = []
for root, dirs, files in os.walk("./"):
	for file in files:
		if file.endswith(".mp3"):
			array.append(os.path.abspath(os.path.join(root, file)))

con = lite.connect('musicLibrary.sqlite3')

with con:
	cur = con.cursor()
	#albums
	cur.execute('''CREATE TABLE IF NOT EXISTS "albums" (
			"albumGenre" Text, 
			"albumID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
			"albumName" Text, 
			"albumYear" Text, 
			"albumImagePath" Text,
			"artistID" Integer, 
			CONSTRAINT "lnk_albums_artists2" FOREIGN KEY ( "artistID" ) REFERENCES "artists"( "artistID" )
		)''')
	
	#artists
	cur.execute('''CREATE TABLE IF NOT EXISTS "artists" (
			"artistID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
			"artistName" Text,
			"artistImagePath" Text
		)''')
	
	#songs
	cur.execute('''CREATE TABLE IF NOT EXISTS "songs" (
			"albumID"  Integer, 
			"songID" Integer NOT NULL PRIMARY KEY AUTOINCREMENT, 
			"songName" Text, 
			CONSTRAINT "albumID" FOREIGN KEY ( "albumID" ) REFERENCES "albums"( "albumID" )
		)''')

	#library
	cur.execute('''CREATE TABLE IF NOT EXISTS "library" (
			"songID" Integer, 
			"path" Text, 
			"rating" Integer, 
			"skipCount" Integer, 
			"playCount" Integer, 
			"bitRate" Integer, 
			"sampleRate" Integer,
			"kind" Text, 
			"lastPlayed" DateTime, 
			"length" Integer, 
			CONSTRAINT "songID-library" FOREIGN KEY ("songID") REFERENCES "songs"("songID")
		)''')
	


	for a in array:
		f = taglib.File(a)

		# if the song already exists the library, then skip..
		cur.execute('SELECT path FROM library WHERE library.path == ?', (a,))
		Path = cur.fetchone()

		# if song does not exisst in library, do this
		# artist
		if Path is None:
			cur.execute('SELECT artistID FROM artists WHERE artists.artistName == ?', (f.tags["ARTIST"][0],))
			ArtistID = cur.fetchone()
			
			if ArtistID is None:
				cur.execute('INSERT INTO artists (artistName, artistImagePath) VALUES (?,?)', (f.tags["ARTIST"][0], art.artistSearch((f.tags["ARTIST"][0],), download=True)))
				cur.execute('SELECT artistID FROM artists WHERE artists.artistName == ?', (f.tags["ARTIST"][0],))
				ArtistID = cur.fetchone()
				

			

			# album
			cur.execute('SELECT albumID FROM albums WHERE albums.albumName == ? AND albums.artistID == ?', (f.tags["ALBUM"][0], ArtistID[0],))
			AlbumID = cur.fetchone()

			if AlbumID is None:
				cur.execute('INSERT INTO albums (albumName, artistID, albumImagePath) VALUES (?,?,?)', (f.tags["ALBUM"][0], ArtistID[0], art.albumSearch((f.tags["ALBUM"][0]), download=True)))
				cur.execute('SELECT albumID FROM albums WHERE albums.albumName == ?AND albums.artistID == ?', (f.tags["ALBUM"][0], ArtistID[0],))
				AlbumID = cur.fetchone()
				



			#song
			cur.execute('SELECT songID FROM songs WHERE songs.songName == ? AND songs.albumID == ?', (f.tags["TITLE"][0], AlbumID[0],))
			SongID = cur.fetchone()

			if SongID is None:
				cur.execute('INSERT INTO songs (songName, albumID) VALUES (?,?)', (f.tags["TITLE"][0], AlbumID[0],))
				cur.execute('SELECT songID FROM songs WHERE songs.songName == ? AND songs.albumID == ?', (f.tags["TITLE"][0], AlbumID[0],))
				SongID = cur.fetchone()


			cur.execute('INSERT INTO library (songID, path, bitRate, sampleRate, kind, length) VALUES (?,?,?,?,?,?)', (SongID[0], a, f.bitrate, f.sampleRate, "MPEG Audio File", f.length))


		#cur.execute("INSERT INTO music (artist, album, song, path, rating, playCount, skipCount, kind, bitRate, lastPlayed, sampleRate, length) VALUES(?,?,?,?,?,?,?,?,?,?,?,?)", 
			#(f.tags["ARTIST"][0], f.tags["ALBUM"][0], f.tags["TITLE"][0], a, 0, 0, 0, "MPEG Audio File", f.bitrate, "", f.sampleRate, f.length))
con.close()