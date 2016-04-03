# Kevin Doveton 2016
clientId = '16a6b2d528cb484e9710ee291b2b195f'
clientSecret = '3d87af766fc74f51801460aefb80a899'

baseUrl = 'https://api.spotify.com'
search = baseUrl + '/v1/search'

import requests, os, uuid, shutil
cache = os.path.dirname(os.path.realpath(__file__)) + '/cache/'
if not os.path.exists(cache):
    os.makedirs(cache)

# class art:
def artistSearch(artistName, download=False):
	payload = {
		'q' : artistName,
		'type' : 'artist'
	}
	outName = cache+str(uuid.uuid4())+'-'+str(artistName)
	try:
		url = requests.get(search, params=payload).json()['artists']['items'][0]['images'][0]['url']
		if download == False:
			return url
		else:
			return downloadImage(url, outName+'.jpg')
	except Exception:
		return ''


def albumSearch(albumName, year="", artist="", download=False):
	if str(albumName) == "":
		return ''

	# get us a base query, we'll make this more specific
	query = 'album:'+str(albumName)
	outName = cache+str(uuid.uuid4())+'-'+str(albumName)
	# if an artist was included
	if str(artist) != "":
		query += ' artist:'+str(artist)
		outName += '-'+str(artist)

	if str(year) != "":
		try:
			query += ' year:'+int(year)
		except Exception:
			pass

	payload = {
		'q' : query,
		'type' : 'album',
		'limit' : '1'
	}
	try:
		url = requests.get(search, params=payload).json()['albums']['items'][0]['images'][0]['url']
		if download == False:
			return url
		else:
			return downloadImage(url, outName+'.jpg')
	except Exception:
		return ''

def downloadImage(url, outName):
	imageRequest = requests.get(url, stream=True)
	with open(outName, 'wb') as out_file:
		shutil.copyfileobj(imageRequest.raw, out_file)
	del imageRequest
	return outName