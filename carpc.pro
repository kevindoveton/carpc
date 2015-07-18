#-------------------------------------------------
#
# Project created by QtCreator 2015-07-10T08:02:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = carpc
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    libraries/SQLiteCpp/Column.cpp \
    libraries/SQLiteCpp/Database.cpp \
    libraries/SQLiteCpp/Statement.cpp \
    libraries/SQLiteCpp/Transaction.cpp \
    libraries/taglib/bindings/c/tag_c.cpp \
    libraries/taglib/CMakeFiles/3.2.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    libraries/taglib/CMakeFiles/feature_tests.cxx \
    libraries/taglib/examples/framelist.cpp \
    libraries/taglib/examples/strip-id3v1.cpp \
    libraries/taglib/examples/tagreader.cpp \
    libraries/taglib/examples/tagwriter.cpp \
    libraries/taglib/taglib/ape/apefile.cpp \
    libraries/taglib/taglib/ape/apefooter.cpp \
    libraries/taglib/taglib/ape/apeitem.cpp \
    libraries/taglib/taglib/ape/apeproperties.cpp \
    libraries/taglib/taglib/ape/apetag.cpp \
    libraries/taglib/taglib/asf/asfattribute.cpp \
    libraries/taglib/taglib/asf/asffile.cpp \
    libraries/taglib/taglib/asf/asfpicture.cpp \
    libraries/taglib/taglib/asf/asfproperties.cpp \
    libraries/taglib/taglib/asf/asftag.cpp \
    libraries/taglib/taglib/flac/flacfile.cpp \
    libraries/taglib/taglib/flac/flacmetadatablock.cpp \
    libraries/taglib/taglib/flac/flacpicture.cpp \
    libraries/taglib/taglib/flac/flacproperties.cpp \
    libraries/taglib/taglib/flac/flacunknownmetadatablock.cpp \
    libraries/taglib/taglib/it/itfile.cpp \
    libraries/taglib/taglib/it/itproperties.cpp \
    libraries/taglib/taglib/mod/modfile.cpp \
    libraries/taglib/taglib/mod/modfilebase.cpp \
    libraries/taglib/taglib/mod/modproperties.cpp \
    libraries/taglib/taglib/mod/modtag.cpp \
    libraries/taglib/taglib/mp4/mp4atom.cpp \
    libraries/taglib/taglib/mp4/mp4coverart.cpp \
    libraries/taglib/taglib/mp4/mp4file.cpp \
    libraries/taglib/taglib/mp4/mp4item.cpp \
    libraries/taglib/taglib/mp4/mp4properties.cpp \
    libraries/taglib/taglib/mp4/mp4tag.cpp \
    libraries/taglib/taglib/mpc/mpcfile.cpp \
    libraries/taglib/taglib/mpc/mpcproperties.cpp \
    libraries/taglib/taglib/mpeg/id3v1/id3v1genres.cpp \
    libraries/taglib/taglib/mpeg/id3v1/id3v1tag.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/attachedpictureframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/commentsframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/ownershipframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/popularimeterframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/privateframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/relativevolumeframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/textidentificationframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/unknownframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/frames/urllinkframe.cpp \
    libraries/taglib/taglib/mpeg/id3v2/id3v2extendedheader.cpp \
    libraries/taglib/taglib/mpeg/id3v2/id3v2footer.cpp \
    libraries/taglib/taglib/mpeg/id3v2/id3v2frame.cpp \
    libraries/taglib/taglib/mpeg/id3v2/id3v2framefactory.cpp \
    libraries/taglib/taglib/mpeg/id3v2/id3v2header.cpp \
    libraries/taglib/taglib/mpeg/id3v2/id3v2synchdata.cpp \
    libraries/taglib/taglib/mpeg/id3v2/id3v2tag.cpp \
    libraries/taglib/taglib/mpeg/mpegfile.cpp \
    libraries/taglib/taglib/mpeg/mpegheader.cpp \
    libraries/taglib/taglib/mpeg/mpegproperties.cpp \
    libraries/taglib/taglib/mpeg/xingheader.cpp \
    libraries/taglib/taglib/ogg/flac/oggflacfile.cpp \
    libraries/taglib/taglib/ogg/opus/opusfile.cpp \
    libraries/taglib/taglib/ogg/opus/opusproperties.cpp \
    libraries/taglib/taglib/ogg/speex/speexfile.cpp \
    libraries/taglib/taglib/ogg/speex/speexproperties.cpp \
    libraries/taglib/taglib/ogg/vorbis/vorbisfile.cpp \
    libraries/taglib/taglib/ogg/vorbis/vorbisproperties.cpp \
    libraries/taglib/taglib/ogg/oggfile.cpp \
    libraries/taglib/taglib/ogg/oggpage.cpp \
    libraries/taglib/taglib/ogg/oggpageheader.cpp \
    libraries/taglib/taglib/ogg/xiphcomment.cpp \
    libraries/taglib/taglib/riff/aiff/aifffile.cpp \
    libraries/taglib/taglib/riff/aiff/aiffproperties.cpp \
    libraries/taglib/taglib/riff/wav/infotag.cpp \
    libraries/taglib/taglib/riff/wav/wavfile.cpp \
    libraries/taglib/taglib/riff/wav/wavproperties.cpp \
    libraries/taglib/taglib/riff/rifffile.cpp \
    libraries/taglib/taglib/s3m/s3mfile.cpp \
    libraries/taglib/taglib/s3m/s3mproperties.cpp \
    libraries/taglib/taglib/toolkit/tbytevector.cpp \
    libraries/taglib/taglib/toolkit/tbytevectorlist.cpp \
    libraries/taglib/taglib/toolkit/tbytevectorstream.cpp \
    libraries/taglib/taglib/toolkit/tdebug.cpp \
    libraries/taglib/taglib/toolkit/tdebuglistener.cpp \
    libraries/taglib/taglib/toolkit/tfile.cpp \
    libraries/taglib/taglib/toolkit/tfilestream.cpp \
    libraries/taglib/taglib/toolkit/tiostream.cpp \
    libraries/taglib/taglib/toolkit/tpropertymap.cpp \
    libraries/taglib/taglib/toolkit/trefcounter.cpp \
    libraries/taglib/taglib/toolkit/tstring.cpp \
    libraries/taglib/taglib/toolkit/tstringlist.cpp \
    libraries/taglib/taglib/toolkit/unicode.cpp \
    libraries/taglib/taglib/trueaudio/trueaudiofile.cpp \
    libraries/taglib/taglib/trueaudio/trueaudioproperties.cpp \
    libraries/taglib/taglib/wavpack/wavpackfile.cpp \
    libraries/taglib/taglib/wavpack/wavpackproperties.cpp \
    libraries/taglib/taglib/xm/xmfile.cpp \
    libraries/taglib/taglib/xm/xmproperties.cpp \
    libraries/taglib/taglib/audioproperties.cpp \
    libraries/taglib/taglib/fileref.cpp \
    libraries/taglib/taglib/tag.cpp \
    libraries/taglib/taglib/tagunion.cpp \
    libraries/taglib/tests/main.cpp \
    libraries/taglib/tests/test_aiff.cpp \
    libraries/taglib/tests/test_ape.cpp \
    libraries/taglib/tests/test_apetag.cpp \
    libraries/taglib/tests/test_asf.cpp \
    libraries/taglib/tests/test_bytevector.cpp \
    libraries/taglib/tests/test_bytevectorlist.cpp \
    libraries/taglib/tests/test_bytevectorstream.cpp \
    libraries/taglib/tests/test_fileref.cpp \
    libraries/taglib/tests/test_flac.cpp \
    libraries/taglib/tests/test_flacpicture.cpp \
    libraries/taglib/tests/test_flacunknownmetadatablock.cpp \
    libraries/taglib/tests/test_id3v1.cpp \
    libraries/taglib/tests/test_id3v2.cpp \
    libraries/taglib/tests/test_info.cpp \
    libraries/taglib/tests/test_it.cpp \
    libraries/taglib/tests/test_list.cpp \
    libraries/taglib/tests/test_map.cpp \
    libraries/taglib/tests/test_mod.cpp \
    libraries/taglib/tests/test_mp4.cpp \
    libraries/taglib/tests/test_mp4coverart.cpp \
    libraries/taglib/tests/test_mp4item.cpp \
    libraries/taglib/tests/test_mpc.cpp \
    libraries/taglib/tests/test_mpeg.cpp \
    libraries/taglib/tests/test_ogg.cpp \
    libraries/taglib/tests/test_oggflac.cpp \
    libraries/taglib/tests/test_opus.cpp \
    libraries/taglib/tests/test_propertymap.cpp \
    libraries/taglib/tests/test_riff.cpp \
    libraries/taglib/tests/test_s3m.cpp \
    libraries/taglib/tests/test_string.cpp \
    libraries/taglib/tests/test_synchdata.cpp \
    libraries/taglib/tests/test_trueaudio.cpp \
    libraries/taglib/tests/test_wav.cpp \
    libraries/taglib/tests/test_wavpack.cpp \
    libraries/taglib/tests/test_xiphcomment.cpp \
    libraries/taglib/tests/test_xm.cpp \
    libraries/tinyxml2/tinyxml2.cpp \
    listviewmusicdelegate.cpp \
    libraries/bass/3dtest/3dtest.c \
    libraries/bass/basstest/basstest.c \
    libraries/bass/contest/contest.c \
    libraries/bass/custloop/custloop.c \
    libraries/bass/dsptest/dsptest.c \
    libraries/bass/fxtest/fxtest.c \
    libraries/bass/list/list.c \
    libraries/bass/livespec/livespec.c \
    libraries/bass/modtest/modtest.c \
    libraries/bass/multi/multi.c \
    libraries/bass/netradio/netradio.c \
    libraries/bass/plugins/plugins.c \
    libraries/bass/rectest/rectest.c \
    libraries/bass/speakers/speakers.c \
    libraries/bass/spectrum/spectrum.c \
    libraries/bass/synth/synth.c \
    libraries/bass/writewav/writewav.c \
    libraries/taglib/CMakeFiles/3.2.3/CompilerIdC/CMakeCCompilerId.c \
    libraries/taglib/CMakeFiles/CheckTypeSize/CMAKE_SIZEOF_UNSIGNED_SHORT.c \
    libraries/taglib/CMakeFiles/CheckTypeSize/SIZEOF_INT.c \
    libraries/taglib/CMakeFiles/CheckTypeSize/SIZEOF_LONGLONG.c \
    libraries/taglib/CMakeFiles/CheckTypeSize/SIZEOF_SHORT.c \
    libraries/taglib/CMakeFiles/CheckTypeSize/SIZEOF_WCHAR_T.c \
    libraries/taglib/CMakeFiles/feature_tests.c \
    libraries/taglib/examples/tagreader_c.c


HEADERS  += mainwindow.h \
    libraries/bass/bass.h \
    libraries/SQLiteCpp/Assertion.h \
    libraries/SQLiteCpp/Column.h \
    libraries/SQLiteCpp/Database.h \
    libraries/SQLiteCpp/Exception.h \
    libraries/SQLiteCpp/SQLiteCpp.h \
    libraries/SQLiteCpp/Statement.h \
    libraries/SQLiteCpp/Transaction.h \
    ClassMusic.h \
    ui_mainwindow.h \
    listviewmusicdelegate.h \
    libraries/taglib/bindings/c/tag_c.h \
    libraries/taglib/taglib/ape/apefile.h \
    libraries/taglib/taglib/ape/apefooter.h \
    libraries/taglib/taglib/ape/apeitem.h \
    libraries/taglib/taglib/ape/apeproperties.h \
    libraries/taglib/taglib/ape/apetag.h \
    libraries/taglib/taglib/asf/asfattribute.h \
    libraries/taglib/taglib/asf/asffile.h \
    libraries/taglib/taglib/asf/asfpicture.h \
    libraries/taglib/taglib/asf/asfproperties.h \
    libraries/taglib/taglib/asf/asftag.h \
    libraries/taglib/taglib/flac/flacfile.h \
    libraries/taglib/taglib/flac/flacmetadatablock.h \
    libraries/taglib/taglib/flac/flacpicture.h \
    libraries/taglib/taglib/flac/flacproperties.h \
    libraries/taglib/taglib/flac/flacunknownmetadatablock.h \
    libraries/taglib/taglib/it/itfile.h \
    libraries/taglib/taglib/it/itproperties.h \
    libraries/taglib/taglib/mod/modfile.h \
    libraries/taglib/taglib/mod/modfilebase.h \
    libraries/taglib/taglib/mod/modfileprivate.h \
    libraries/taglib/taglib/mod/modproperties.h \
    libraries/taglib/taglib/mod/modtag.h \
    libraries/taglib/taglib/mp4/mp4atom.h \
    libraries/taglib/taglib/mp4/mp4coverart.h \
    libraries/taglib/taglib/mp4/mp4file.h \
    libraries/taglib/taglib/mp4/mp4item.h \
    libraries/taglib/taglib/mp4/mp4properties.h \
    libraries/taglib/taglib/mp4/mp4tag.h \
    libraries/taglib/taglib/mpc/mpcfile.h \
    libraries/taglib/taglib/mpc/mpcproperties.h \
    libraries/taglib/taglib/mpeg/id3v1/id3v1genres.h \
    libraries/taglib/taglib/mpeg/id3v1/id3v1tag.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/attachedpictureframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/commentsframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/ownershipframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/popularimeterframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/privateframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/relativevolumeframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/textidentificationframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/unknownframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.h \
    libraries/taglib/taglib/mpeg/id3v2/frames/urllinkframe.h \
    libraries/taglib/taglib/mpeg/id3v2/id3v2extendedheader.h \
    libraries/taglib/taglib/mpeg/id3v2/id3v2footer.h \
    libraries/taglib/taglib/mpeg/id3v2/id3v2frame.h \
    libraries/taglib/taglib/mpeg/id3v2/id3v2framefactory.h \
    libraries/taglib/taglib/mpeg/id3v2/id3v2header.h \
    libraries/taglib/taglib/mpeg/id3v2/id3v2synchdata.h \
    libraries/taglib/taglib/mpeg/id3v2/id3v2tag.h \
    libraries/taglib/taglib/mpeg/mpegfile.h \
    libraries/taglib/taglib/mpeg/mpegheader.h \
    libraries/taglib/taglib/mpeg/mpegproperties.h \
    libraries/taglib/taglib/mpeg/xingheader.h \
    libraries/taglib/taglib/ogg/flac/oggflacfile.h \
    libraries/taglib/taglib/ogg/opus/opusfile.h \
    libraries/taglib/taglib/ogg/opus/opusproperties.h \
    libraries/taglib/taglib/ogg/speex/speexfile.h \
    libraries/taglib/taglib/ogg/speex/speexproperties.h \
    libraries/taglib/taglib/ogg/vorbis/vorbisfile.h \
    libraries/taglib/taglib/ogg/vorbis/vorbisproperties.h \
    libraries/taglib/taglib/ogg/oggfile.h \
    libraries/taglib/taglib/ogg/oggpage.h \
    libraries/taglib/taglib/ogg/oggpageheader.h \
    libraries/taglib/taglib/ogg/xiphcomment.h \
    libraries/taglib/taglib/riff/aiff/aifffile.h \
    libraries/taglib/taglib/riff/aiff/aiffproperties.h \
    libraries/taglib/taglib/riff/wav/infotag.h \
    libraries/taglib/taglib/riff/wav/wavfile.h \
    libraries/taglib/taglib/riff/wav/wavproperties.h \
    libraries/taglib/taglib/riff/rifffile.h \
    libraries/taglib/taglib/s3m/s3mfile.h \
    libraries/taglib/taglib/s3m/s3mproperties.h \
    libraries/taglib/taglib/toolkit/taglib.h \
    libraries/taglib/taglib/toolkit/tbytevector.h \
    libraries/taglib/taglib/toolkit/tbytevectorlist.h \
    libraries/taglib/taglib/toolkit/tbytevectorstream.h \
    libraries/taglib/taglib/toolkit/tdebug.h \
    libraries/taglib/taglib/toolkit/tdebuglistener.h \
    libraries/taglib/taglib/toolkit/tfile.h \
    libraries/taglib/taglib/toolkit/tfilestream.h \
    libraries/taglib/taglib/toolkit/tiostream.h \
    libraries/taglib/taglib/toolkit/tlist.h \
    libraries/taglib/taglib/toolkit/tmap.h \
    libraries/taglib/taglib/toolkit/tpropertymap.h \
    libraries/taglib/taglib/toolkit/trefcounter.h \
    libraries/taglib/taglib/toolkit/tstring.h \
    libraries/taglib/taglib/toolkit/tstringlist.h \
    libraries/taglib/taglib/toolkit/tutils.h \
    libraries/taglib/taglib/toolkit/unicode.h \
    libraries/taglib/taglib/trueaudio/trueaudiofile.h \
    libraries/taglib/taglib/trueaudio/trueaudioproperties.h \
    libraries/taglib/taglib/wavpack/wavpackfile.h \
    libraries/taglib/taglib/wavpack/wavpackproperties.h \
    libraries/taglib/taglib/xm/xmfile.h \
    libraries/taglib/taglib/xm/xmproperties.h \
    libraries/taglib/taglib/audioproperties.h \
    libraries/taglib/taglib/fileref.h \
    libraries/taglib/taglib/tag.h \
    libraries/taglib/taglib/taglib_export.h \
    libraries/taglib/taglib/tagunion.h \
    libraries/taglib/tests/utils.h \
    libraries/taglib/config.h \
    libraries/taglib/taglib_config.h \
    libraries/tinyxml2/tinyxml2.h


#FORMS    += mainwindow.ui


# bass support
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libraries/bass/release/ -lbass
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libraries/bass/debug/ -lbass
else:unix: LIBS += -L$$PWD/libraries/bass/ -lbass

INCLUDEPATH += $$PWD/libraries/bass
DEPENDPATH += $$PWD/libraries/bass

# c++ 11 support
CONFIG += c++11
CONFIG += console

OUTPUT +=Console

# pkgconfig include
unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += alsa
unix: PKGCONFIG += taglib
unix: PKGCONFIG += tinyxml
unix: PKGCONFIG += sqlite3
