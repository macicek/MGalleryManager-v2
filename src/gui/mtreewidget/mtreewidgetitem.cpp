#include "gui/mtreewidget/mtreewidget.h"
#include "gui/mtreewidget/mtreewidgetitem.h"
#include "core/mgallery.h"
#include "core/mphoto.h"

namespace mgui
{

/**
 * constructor
 * casts to an MObject and creates proper widget details
 */
MTreeWidgetItem::MTreeWidgetItem(MTreeWidget* widget, mcore::MGallery* gallery)
{
    _widget = widget;
    _obj = gallery;

    // widget details
    setText(0, QString(gallery->name().c_str()));
    gallery->setTreeWidgetItem(this);
}

/**
 * constructor
 * casts to an MObject and creates proper widget details
 * Photos have different detail structure than Galleries, therefore we can't template these
 */
MTreeWidgetItem::MTreeWidgetItem(MTreeWidget* widget, mcore::MPhoto* photo)
{
    _widget = widget;
    _obj = photo;

    // widget details
    setText(0, QString(photo->name().c_str()));
    photo->setTreeWidgetItem(this);
}

/**
 * destructor
 */
MTreeWidgetItem::~MTreeWidgetItem()
{

}

/**
 * highlights a line in the tree
 * \param apply used to display or hide the background color
 */
void MTreeWidgetItem::setFavourite(bool apply)
{
    if (apply)
	setBackground(0, QBrush(QColor(Qt::yellow)));
    else
	setBackground(0, QBrush(QColor(Qt::white)));
}

/**
 * returns a currently selected QTreeWidgetItem, casts it to an MTreeWidgetItem
 * \return MTreeWidget item
 */
MTreeWidgetItem* MTreeWidget::selected()
{
    return static_cast<MTreeWidgetItem*>(currentItem());
}

void MTreeWidgetItem::destroy()
{
    _widget->remove(this);

    delete this;
}

} // NAMESPACE GUI
