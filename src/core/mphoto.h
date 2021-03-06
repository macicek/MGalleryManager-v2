#ifndef MPHOTO_H
#define MPHOTO_H

#include <list>

#include <QFileInfo>
#include <QPixmap>
#include <QImage>
#include <QLabel>

#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>
#include <boost/gil/extension/io/jpeg_io.hpp>
#include <boost/gil/extension/numeric/sampler.hpp>
#include <boost/gil/extension/numeric/resample.hpp>
#include <boost/assert.hpp>

#include "core/mobject.h"
#include "core/mimage.h"
#include "core/mnumeric.h"
#include "core/mphotoinfo.h"

const unsigned int HISTORY_SIZE = 10;

namespace mgui
{
    class MGridWidgetViewer;
}

namespace mcore
{                
    class MGallery;
    class MPhoto : public MObject
    {
	public:	    
	    MPhoto(MGallery* parent /* = NULL */); // defaulty must have a parent gallery !
	    MPhoto(MPhotoInfo info, MGallery* parent /* = NULL */); // defaulty must have a parent gallery !
	    ~MPhoto();

	    // set and get
	    MPhotoInfo* info() const { return _info; } // when we want access to the whole info
	    std::string path() const { return _info->path(); }
	    std::string name() const { return _info->name(); }
	    std::string description() const { return _info->description(); }
	    std::string filename() const { return _info->fileName(); }
	    int width() const { return _image.width(); }
	    int height() const { return _image.height(); }

	    void setPath(std::string path){ _info->setPath(path); }
	    void setName(std::string name){ _info->setName(name); }
	    void setDescription(std::string description){ _info->setDescription(description); }

	    // gui helpers
	    // we use these to generate different gui features like thumbnails
	    QPixmap pixmapFromView(const QImage& image);
	    QPixmap pixmapFromView(int width, int height);
	    QPixmap pixmapFromView(int maxSize = 0); // we don't scale
	    QPixmap pixmapFromFile(int maxSize, bool force = false);
	    template <typename SourceView>
	    QImage viewToQImage(const SourceView& source);

	    // transforms
	    // rotation
	    void rotate(mimage::RGB background, double angle);
	    template <typename SourceView, typename DestView>
	    void rotate(const SourceView& source, const DestView& dest, double angle);
	    template <typename SourceView>
	    boost::gil::matrix3x2<double> getTranslationMatrix(const SourceView& source, double angle);

	    // resize
	    void resize(double width, double height);
	    void resize(double maxSize);
	    template <typename SourceView, typename DestView>
	    void resize(const SourceView& source, const DestView& dest);

	    // color change
	    // value ranges from -255.0 to 255.0
	    void brightness(double value);
	    template <typename SourceView, typename DestView>
	    void brightness(const SourceView& source, const DestView& dest, double value);

	    void contrast(double value);
	    template <typename SourceView, typename DestView>
	    void contrast(const SourceView& source, const DestView& dest, double value);

	    void saturation(double value);
	    template <typename SourceView, typename DestView>
	    void saturation(const SourceView& source, const DestView& dest, double value);

	    void blackandwhite();

	    // loading/saving
	    bool load(std::string path);
	    bool save(bool force = false);
	    bool saveAs(std::string path, int size = 0, bool force = false);

	    // history
	    void pushToHistory(boost::gil::rgb8_image_t image);
	    void popFromHistory();
	    bool backward();
	    bool forward();

	private:	    
	    // fileinfo about the original file
	    // contains all kinds of metadata, filepath, ...
	    MPhotoInfo*	    _info;

	    // color and image representations
	    boost::gil::rgb8_image_t _image;
	    boost::gil::rgb8_image_t _originalImage;
	    std::list<boost::gil::rgb8_image_t> _history;
	    std::list<boost::gil::rgb8_image_t>::iterator _historyIt;
    };
}

#endif // MPHOTO_H
