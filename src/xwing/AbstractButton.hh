//
// AbstractButton.hh
//

// All rights reserved.
//


#ifndef DEF_AbstractButton


class AbstractButton : public XComponent
{
	private: PtrList<ActionListener> *al;

	public: AbstractButton();
	public: virtual void addActionListener ( ActionListener* );
	protected: virtual void fireActionPerformed ( ActionEvent* );

	public: virtual AbstractButton* clone() = 0;
};


#  define DEF_AbstractButton
#endif
