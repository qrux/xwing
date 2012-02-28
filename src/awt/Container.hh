//
// Container.hh
//

// All rights reserved.
//


#ifndef DEF_awt_Container


class LayoutManager;

namespace awt {


class Container : public Component {

	private: PtrList<Component> *list;
	private: LayoutManager* lm;

	protected: Container();
	public: virtual Component* add ( Component* );
	public: virtual Component* getComponent ( unsigned int );
	public: virtual Component* getComponentAt ( int, int );
	public: virtual unsigned int getComponentCount();
	public: virtual LayoutManager* getLayout();
	public: virtual void setLayout ( LayoutManager* );
	public: virtual void paintAll ( Graphics* );
	public: virtual void paintComponents ( Graphics* );
	public: virtual void update ( Graphics* );
	public: virtual void validate();
	public: virtual void removeNotify();

	public: virtual Container* clone() = 0;
	};


}


#  define DEF_awt_Container
#endif
