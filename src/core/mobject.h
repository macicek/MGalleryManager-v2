#ifndef MOBJECT_H
#define MOBJECT_H

#include <string>

namespace core
{
    class MGallery;
    class MDatabase;
    class MObject
    {
	public:
	    MObject(MGallery* parent = 0);
	    ~MObject();
	    std::string name(){ return _name; }
	    void setName(std::string name){ _name = name; }

	private:
	    std::string _name;
	    MDatabase* _parentDatabase;
	    MGallery* _parentGallery;
    };
}

#endif // MOBJECT_H
