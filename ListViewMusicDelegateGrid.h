// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#ifndef LISTVIEWMUSICDELEGATEGRID_H
#define LISTVIEWMUSICDELEGATEGRID_H
#include <QListView>
#include <QItemDelegate>
#include <QPainter>
#include <QFile>
#include <QFontDatabase>
#include <QDebug>
#include <QApplication>

class listViewMusicDelegateGrid : public QAbstractItemDelegate
{
	public:
		listViewMusicDelegateGrid(QObject *parent=0) : QAbstractItemDelegate(parent){}
		void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
		{
			// get the image
			// this uses the DecorationRole flag,
			// index = 0
			QImage ic = qvariant_cast<QImage>(index.data(Qt::DecorationRole));

			// scale image so that at least width or height
			// is equal to the size of the box
			ic = ic.scaled(option.rect.width(), option.rect.height(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

			// find the centre of the box and image
			// set crop margins from those points
			int imgWidthCentre = ic.width()/2;
			int boxWidthCentre = option.rect.width()/2;
			int cropWidth = imgWidthCentre-boxWidthCentre;

			int imgHeightCentre = ic.height()/2;
			int boxHeightCentre = option.rect.height()/2;
			int cropHeight = imgHeightCentre - boxHeightCentre;

			// crop the image so that it will be centered
			// inside of the box
			QImage icCrop = ic.copy(cropWidth, cropHeight, option.rect.width(), option.rect.height());

			// painter draw image format:
			// painter->drawImage(QRect(rectangle), QImage(image))
			painter->drawImage(option.rect, icCrop);

			// get the text
			// this uses the DisplayRole flag
			// index  = 0
			QString txt = index.data(Qt::DisplayRole).toString();

			// add a little padding to the bottom and left edge of the image
			QRect textRect = option.rect.adjusted(+(option.rect.height()/40), 0, -(option.rect.height()/40), -(option.rect.height()/40) );
			QRect boundingRect = option.rect;
			// set the pen colour as white
			QPen textPen(QColor("#FFFFFF"));
			painter->setPen(textPen);

			// draw the text, aligned bottom and left - padding is already taken care of
			// painter->drawText(Qrect(textRectangle), Option|Option, QString(text), QRect(boundingRectangle);
			painter->drawText(textRect, Qt::AlignBottom|Qt::AlignLeft|Qt::TextWordWrap, txt, &boundingRect);
		}

		QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
		{
			int x = option.rect.width()*0.95;
			int y = option.rect.height()*0.95;
			return QSize(x, y);
		}
};

#endif // LISTVIEWMUSICDELEGATEGRID_H
