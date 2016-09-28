#ifndef LISTVIEWMUSICDELEGATELIST_H
#define LISTVIEWMUSICDELEGATELIST_H
// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#include <QListView>
#include <QItemDelegate>
#include <QPainter>
#include <QFile>
#include <QFontDatabase>
#include <QDebug>
#include <QApplication>

class listViewMusicDelegateList : public QAbstractItemDelegate
{
	public:
		listViewMusicDelegateList(QObject *parent=0) : QAbstractItemDelegate(parent){}
		void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
		{
			// get the text
			// this uses the DisplayRole flag
			// index  = 0
			QString txt = index.data(Qt::DisplayRole).toString();

			// add a little padding to the bottom and left edge of the image
			QRect textRect = option.rect.adjusted(+(option.rect.height()/40), 0, -(option.rect.height()/40), -(option.rect.height()/40) );
			QRect boundingRect = option.rect;
			// set the pen colour as white
			QPen textPen(QColor("#FFFFFF"));
			QFont font;

			font.setPointSize(font.pointSize()*2);

			painter->setPen(textPen);
			painter->setFont(font);

			// draw the text, aligned bottom and left - padding is already taken care of
			// painter->drawText(Qrect(textRectangle), Option|Option, QString(text), QRect(boundingRectangle);
			painter->drawText(textRect, Qt::AlignLeft|Qt::TextWordWrap, txt, &boundingRect);
		}

		QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
		{
			int x = option.rect.width()*0.95;
			int y = option.rect.height()*0.95;
			return QSize(x, y);
		}
};

#endif // LISTVIEWMUSICDELEGATELIST_H
