//
// XFrame.hh
//

// All rights reserved.
//


#ifndef DEF_XFrame


class XFrame : public Frame {

	private: unsigned int display_width;
	private: unsigned int display_height;

	private: XPanel content_pane;
	
	public: XFrame();
	public: XFrame ( String* );
	public: XFrame ( String& );
	public: virtual awt::Container* getContentPane();
	public: virtual Component* getComponentAt ( int, int );
	public: virtual void setBorder ( Border* );
	public: virtual void setSize ( unsigned int, unsigned int );
	public: virtual void setVisible ( bool );
	public: virtual void paint ( Graphics* );
	public: virtual void paintAll ( Graphics* );
	public: virtual void paintComponents ( Graphics* );
	public: virtual void update ( Graphics* );

	public: virtual XFrame* clone();
	};


#  define DEF_XFrame
#endif
