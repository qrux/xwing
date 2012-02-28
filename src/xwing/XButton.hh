//
// XButton.hh
//

// All rights reserved.
//


#ifndef DEF_XButton


class XButton : public AbstractButton, public MouseAdapter
{
    private:
	String* label;

	bool isMouseInside;
	bool isMousePressed;

	Dimension* psize;

    public:
	XButton();
	XButton ( String* );
	XButton ( String& );
	virtual Dimension* getPreferredSize();
	virtual void setText ( String& );
	virtual void paint ( Graphics* );

	virtual void mouseEntered ( MouseEvent* );
	virtual void mouseExited ( MouseEvent* );
	virtual void mousePressed ( MouseEvent* );
	virtual void mouseReleased ( MouseEvent* );
	virtual void mouseClicked ( MouseEvent* );

    private:
	void init();

    public:
	INLINE_GC_OPERATORS;	// This is to resolve the ambiguity; see <defs>

	virtual XButton* clone();
};


#  define DEF_XButton
#endif
