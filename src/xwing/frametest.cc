//////////////////////////////////////////////////
//
// Project homepage:
//   <github page>
//
//////////////////////////////////////////////////

#include <xwing/inc.hh>


class MyLabel : public XLabel, public ActionListener
{
    public:
	MyLabel() :
	    pre(new String("Number of button clicks: "))
	{
		StringBuffer *label = new StringBuffer();

		label->append(pre);
		label->append("0    ");

		this->setText(label->toString());
	}

	virtual void actionPerformed ( ActionEvent* )
	{
		StringBuffer *label = new StringBuffer();

		label->append(pre);
		label->append(new String(++counter));

		this->setText(label->toString());
	}

	////////////////////////////////////////
	// Ugliness that can be auto-generated.
	////////////////////////////////////////

	INLINE_GC_OPERATORS;
	virtual MyLabel* clone() { return new MyLabel(that); }

    private:
	unsigned int counter;
	String *pre;
};



int main()
{
	XFrame* frame = new XFrame(new String("Xwing App"));

	XPanel* panel = new XPanel();
	XButton* swing_button = new XButton(new String("I'm an Xwing button!"));
	MyLabel* swing_label = new MyLabel();

	swing_button->addActionListener(swing_label);

	panel->setLayout(new GridLayout(2,1));
	panel->setBorder(new EmptyBorder(30,30,10,30));
	panel->add(swing_button);
	panel->add(swing_label);

	frame->setSize(300,110);

	awt::Container* c = frame->getContentPane();
	c->setLayout(new GridLayout(1,1));
	c->add(panel);

	frame->setVisible(true);

	return 0;
}
