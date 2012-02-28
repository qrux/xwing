//
// Component.hh
//

// All rights reserved.
//


#ifndef DEF_Component


class MouseListener;
namespace awt { class Container; }


class Component : public Object
{
	friend class awt::Container;

    protected:
	Component* parent;
    private:
	Graphics* graphics;

	int x;
	int y;

	unsigned int width;
	unsigned int height;

	Border* border;

	awt::Font* font;
	Color* foreground;
	Color* background;

	PtrList<MouseListener> *ml_list;


    protected:
	Component();

    public:
	virtual Border* getBorder();
	virtual Dimension* getSize();
	virtual Rectangle* getBounds();
	virtual int getX();
	virtual int getY();
	virtual Component* getParent();
	virtual Graphics* getGraphics();
	virtual awt::Font* getFont();
	virtual FontMetrics* getFontMetrics ( awt::Font* );
	virtual Color* getForeground();
	virtual Color* getBackground();
	virtual Component* getComponentAt ( int, int );
	virtual Dimension* getPreferredSize() = 0;

	virtual void setBorder ( Border* );
	virtual void setFont ( awt::Font* );
	virtual void setForeground ( Color* );
	virtual void setBackground ( Color* );
	virtual void setSize ( Dimension* );
	virtual void setSize ( unsigned int, unsigned int );
	virtual void setLocation ( unsigned int, unsigned int );
	virtual void paint ( Graphics* );
	virtual void repaint();
	virtual void paintAll ( Graphics* );
	virtual void update ( Graphics* );
	virtual void validate();
	virtual void removeNotify();

	void addMouseListener ( MouseListener* );
	virtual void dispatchEvent ( AWTEvent* );

    protected:
	virtual void processEvent ( AWTEvent* );
	virtual void processMouseEvent ( MouseEvent* );

    public:
	virtual Component* clone() = 0;
};


#  define DEF_Component
#endif
