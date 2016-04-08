// --------------------------
// Kevin Doveton
// Copyright 2015
// --------------------------

#ifndef LISTVIEWMUSICDELEGATE_H
#define LISTVIEWMUSICDELEGATE_H
#include <QListView>
#include <QItemDelegate>
#include <QPainter>
#include <QFile>
#include <QFontDatabase>
#include <QDebug>

class listViewMusicDelegate : public QAbstractItemDelegate
{
	public:
		listViewMusicDelegate(QObject *parent=0) : QAbstractItemDelegate(parent){}
		void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
		{
			// this added a blue highlight when clicked
//			if(option.state & QStyle::State_Selected){
//				painter->fillRect(option.rect, option.palette.color(QPalette::Highlight));
//			}

			// this created a nice little icon
//			QIcon ic = QIcon(qvariant_cast<QPixmap>(index.data(Qt::DecorationRole)));
			QPixmap ic = qvariant_cast<QPixmap>(index.data(Qt::DecorationRole));
			ic = ic.scaled(option.rect.width(), option.rect.height(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

			QString txt = index.data(Qt::DisplayRole).toString();


//			QRect r = option.rect.adjusted(10, -5, 0, 5);

			// this paints the image as a full scale.. need to vcenter still
			// fillRect(x, y, aspect ratio, transformation)
			painter->fillRect(option.rect, ic);


			// this created a nice little icon
//			ic.paint(painter, r, Qt::AlignVCenter|Qt::AlignRight);

			QRect r = option.rect.adjusted(0, 0, 0, -10); // add a little padding to the bottom of the image
			QPen textPen(QColor("#FFFFFF"));
			painter->setPen(textPen);
			painter->drawText(r, Qt::AlignBottom|Qt::AlignLeft|Qt::TextWordWrap, txt, &r);
		}

		QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
		{
			return QSize(200, 200); // need to implement spacing?
			// will then be 410 && 165
		}
};

#endif // LISTVIEWMUSICDELEGATE_H
