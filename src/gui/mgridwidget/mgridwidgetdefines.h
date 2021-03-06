#ifndef MGRIDWIDGETDEFINES_H
#define MGRIDWIDGETDEFINES_H

namespace mgui
{

enum Buttons
{
    BUTTON_EDIT,
    BUTTON_DELETE,
    // BUTTON_FAV,
    // BUTTON_SELECT,

    MAX_BUTTONS
};

// defines
#define GRID_WIDTH	4
#define DEFAULT_VIEWER_IMAGE_SIZE 450

enum GridTypes
{
    GRIDTYPE_ITEM,
    GRIDTYPE_VIEWER,
    GRIDTYPE_THUMBNAIL
};

} // NAMESPACE GUI

#endif // MGRIDWIDGETDEFINES_H
