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

		//		QFile fontFile("resources/fonts/sanFrancisco/sanFranciscoUltralight.ttf");
		//		fontFile.open(QFile::ReadOnly);
		//		int appFontID = QFontDatabase::addApplicationFontFromData(fontFile.readAll());

		//		QFont sanFrancisco(".SFNSDisplay-Ultralight");

		//		painter->setFont(sanFrancisco);
	public:
		listViewMusicDelegate(QObject *parent=0) : QAbstractItemDelegate(parent){}
		void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const{
			if(option.state & QStyle::State_Selected){
				painter->fillRect(option.rect, option.palette.color(QPalette::Highlight));
			}
			;
			QIcon ic = QIcon(qvariant_cast<QPixmap>(index.data(Qt::DecorationRole)));
			QString txt = index.data(Qt::DisplayRole).toString();
			QRect r = option.rect.adjusted(10, -5, 0, 5);
			//		 14, 5, 168, 168

			//		painter->setFont(sanFrancisco);
			ic.paint(painter, r, Qt::AlignVCenter|Qt::AlignLeft);
			r = r.adjusted(r.height()+20, 0, 0, 0);

			painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignVCenter|Qt::AlignLeft|Qt::TextWordWrap, txt, &r);
		}

		QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const{
			return QSize(420, 170); // need to implement spacing?
			// will then be 410 && 165
		}
};

#endif // LISTVIEWMUSICDELEGATE_H
