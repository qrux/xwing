/*
 * 1.1+Swing version.
 */

import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class Converter {
    ConversionPanel metricPanel, usaPanel;
    Unit[] metricDistances = new Unit[3];
    Unit[] usaDistances = new Unit[4];
    final static boolean COLORS = false;
    final static boolean DEBUG = false;
    final static String LOOKANDFEEL = null;
    ConverterRangeModel dataModel = new ConverterRangeModel();
    JPanel mainPane;

    /** 
     * Create the ConversionPanels (one for metric, another for U.S.).
     * I used "U.S." because although Imperial and U.S. distance
     * measurements are the same, this program could be extended to
     * include volume measurements, which aren't the same.
     *
     * Put the ConversionPanels into a frame, and bring up the frame.
     */
    public Converter() {
        //Create Unit objects for metric distances, and then 
        //instantiate a ConversionPanel with these Units.
        metricDistances[0] = new Unit("Centimeters", 0.01);
        metricDistances[1] = new Unit("Meters", 1.0);
        metricDistances[2] = new Unit("Kilometers", 1000.0);
        metricPanel = new ConversionPanel(this, "Metric System",
                                          metricDistances,
                                          dataModel);

        //Create Unit objects for U.S. distances, and then 
        //instantiate a ConversionPanel with these Units.
        usaDistances[0] = new Unit("Inches", 0.0254);
        usaDistances[1] = new Unit("Feet", 0.305);
        usaDistances[2] = new Unit("Yards", 0.914);
        usaDistances[3] = new Unit("Miles", 1613.0);
        usaPanel = new ConversionPanel(this, "U.S. System",
                                       usaDistances,
                                       new FollowerRangeModel(dataModel));

        //Create a JPanel, and add the ConversionPanels to it.
        mainPane = new JPanel();
        if (COLORS) {
            mainPane.setBackground(Color.red);
        }
        mainPane.setLayout(new GridLayout(2,1,5,5));
        mainPane.setBorder(BorderFactory.createEmptyBorder(5,5,5,5));
        mainPane.add(metricPanel);
        mainPane.add(usaPanel);
        resetMaxValues(true);
    }

    public void resetMaxValues(boolean resetCurrentValues) {
        double metricMultiplier = metricPanel.getMultiplier();
        double usaMultiplier = usaPanel.getMultiplier();
        int maximum = ConversionPanel.MAX;

        if (metricMultiplier > usaMultiplier) {
            maximum = (int)(ConversionPanel.MAX *
                      (usaMultiplier/metricMultiplier));
        }

        if (DEBUG) {
            System.out.println("in Converter resetMaxValues");
            System.out.println("  metricMultiplier = " 
                                + metricMultiplier
                             + "; usaMultiplier = "
                                + usaMultiplier
                             + "; maximum = " 
                                + maximum);
        }

        dataModel.setMaximum(maximum);

        if (resetCurrentValues) {
            dataModel.setDoubleValue(maximum);
        }
    }

    private static void initLookAndFeel() { 
        String lookAndFeel = null;

        if (LOOKANDFEEL != null) {
            if (LOOKANDFEEL.equals("Metal")) {
                lookAndFeel = UIManager.getCrossPlatformLookAndFeelClassName();
            } else if (LOOKANDFEEL.equals("System")) {
                lookAndFeel = UIManager.getSystemLookAndFeelClassName();
            } else if (LOOKANDFEEL.equals("Mac")) {
                lookAndFeel = "com.sun.java.swing.plaf.mac.MacLookAndFeel";
                //PENDING: check!
            } else if (LOOKANDFEEL.equals("Windows")) {
                lookAndFeel = "com.sun.java.swing.plaf.windows.WindowsLookAndFeel";
            } else if (LOOKANDFEEL.equals("Motif")) {
                lookAndFeel = "com.sun.java.swing.plaf.motif.MotifLookAndFeel";
            }

            if (DEBUG) {
                System.out.println("About to request look and feel: " 
                                   + lookAndFeel);
            }

            try {
                UIManager.setLookAndFeel(lookAndFeel);
            } catch (ClassNotFoundException e) {
                System.err.println("Couldn't find class for specified look and feel:"
                                   + lookAndFeel);
                System.err.println("Did you include the L&F library in the class path?");
                System.err.println("Using the default look and feel.");
            } catch (UnsupportedLookAndFeelException e) {
                System.err.println("Can't use the specified look and feel ("
                                   + lookAndFeel
                                   + ") on this platform.");
                System.err.println("Using the default look and feel.");
            } catch (Exception e) { 
                System.err.println("Couldn't get specified look and feel ("
                                   + lookAndFeel
                                   + "), for some reason.");
                System.err.println("Using the default look and feel.");
                e.printStackTrace();
            } 
        }
    }

    public static void main(String[] args) {
        initLookAndFeel();
        Converter converter = new Converter();

        //Create a new window.
        JFrame f = new JFrame("Converter");
        f.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        //Add the JPanel to the window and display the window.
        //We can use a JPanel for the content pane because
        //JPanel is opaque.
        f.setContentPane(converter.mainPane);
        if (COLORS) {
           //This has no effect, since the JPanel completely
           //covers the content pane.
           f.getContentPane().setBackground(Color.green);
        }

        f.pack();        //Resizes the window to its natural size.
        f.setVisible(true);
    }
}


/*
 * 1.1+Swing version.
 */

import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.text.NumberFormat;

public class ConversionPanel extends JPanel {
    DecimalField textField;
    JComboBox unitChooser;
    JSlider slider;
    ConverterRangeModel sliderModel;
    Converter controller;
    Unit[] units;
    String title;
    final static boolean DEBUG = false;
    final static boolean COLORS = false;
    final static int MAX = 10000;

    ConversionPanel(Converter myController, String myTitle, 
                    Unit[] myUnits,
                    ConverterRangeModel myModel) {
        if (COLORS) {
            setBackground(Color.cyan);
        }
        setBorder(BorderFactory.createCompoundBorder(
                        BorderFactory.createTitledBorder(myTitle),
                        BorderFactory.createEmptyBorder(5,5,5,5)));

        //Save arguments in instance variables.
        controller = myController;
        units = myUnits;
        title = myTitle;
        sliderModel = myModel;

        //Add the text field.  It initially displays "0" and needs
        //to be at least 10 columns wide.
        NumberFormat numberFormat = NumberFormat.getNumberInstance();
        numberFormat.setMaximumFractionDigits(2);
        textField = new DecimalField(0, 10, numberFormat); 
        textField.setValue(sliderModel.getDoubleValue());
        textField.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                sliderModel.setDoubleValue(textField.getValue());
            }
        });

        //Add the combo box.
        unitChooser = new JComboBox(); 
        for (int i = 0; i < units.length; i++) { //Populate it.
            unitChooser.addItem(units[i].description);
        }
        unitChooser.setSelectedIndex(0);
        sliderModel.setMultiplier(units[0].multiplier);
        unitChooser.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                //Set new maximums for the sliders.
                int i = unitChooser.getSelectedIndex();
                sliderModel.setMultiplier(units[i].multiplier);
                controller.resetMaxValues(false);
            }
        });

        //Add the slider.
        slider = new JSlider(sliderModel);
        sliderModel.addChangeListener(new ChangeListener() {
            public void stateChanged(ChangeEvent e) {
                textField.setValue(sliderModel.getDoubleValue());
            }
        });

        //Make the textfield/slider group a fixed size.
        JPanel unitGroup = new JPanel() {
            public Dimension getMinimumSize() {
                return getPreferredSize();
            }
            public Dimension getPreferredSize() {
                return new Dimension(150,
                                     super.getPreferredSize().height);
            }
            public Dimension getMaximumSize() {
                return getPreferredSize();
            }
        };
        if (COLORS) {
            unitGroup.setBackground(Color.blue);
        }
        unitGroup.setBorder(BorderFactory.createEmptyBorder(
                                                0,0,0,5));
        unitGroup.setLayout(new BoxLayout(unitGroup, 
                                          BoxLayout.Y_AXIS));
        unitGroup.add(textField);
        unitGroup.add(slider);

        setLayout(new BoxLayout(this, BoxLayout.X_AXIS));
        add(unitGroup);
        add(unitChooser);
        unitGroup.setAlignmentY(TOP_ALIGNMENT);
        unitChooser.setAlignmentY(TOP_ALIGNMENT);
    }

    /** 
     * Returns the multiplier (units/meter) for the currently
     * selected unit of measurement.
     */
    public double getMultiplier() {
        return sliderModel.getMultiplier();
    }

    public double getValue() {
        return sliderModel.getDoubleValue();
    }
}


/*
 * 1.1+Swing version.
 */

import javax.swing.*;
import javax.swing.event.*;

/** 
 * Based on the source code for DefaultBoundedRangeModel,
 * this class stores its value as a double, rather than 
 * an int.  The minimum value and extent are always 0.
 **/
public class ConverterRangeModel implements BoundedRangeModel {
    protected ChangeEvent changeEvent = null;
    protected EventListenerList listenerList = new EventListenerList();

    protected int maximum = 10000;
    protected int minimum = 0;
    protected int extent = 0;
    protected double value = 0.0;
    protected double multiplier = 1.0;
    protected boolean isAdjusting = false;
    final static boolean DEBUG = false;

    public ConverterRangeModel() {
    }

    public double getMultiplier() {
        if (DEBUG) {
            System.out.println("In ConverterRangeModel getMultiplier");
        }
        return multiplier;
    }

    public void setMultiplier(double multiplier) {
        if (DEBUG) {
            System.out.println("In ConverterRangeModel setMultiplier");
        }
        this.multiplier = multiplier;
        fireStateChanged();
    }

    public int getMaximum() {
        if (DEBUG) {
            System.out.println("In ConverterRangeModel getMaximum");
        }
        return maximum;
    }

    public void setMaximum(int newMaximum) {
        if (DEBUG) {
            System.out.println("In ConverterRangeModel setMaximum");
        }
        setRangeProperties(value, extent, minimum, newMaximum, isAdjusting);
    }

    public int getMinimum() {
        return (int)minimum;
    }

    public void setMinimum(int newMinimum) {
        System.out.println("In ConverterRangeModel setMinimum");
        //Do nothing.
    }

    public int getValue() {
        if (DEBUG) {
            System.out.println("In ConverterRangeModel getValue");
        }
        return (int)getDoubleValue();
    }

    public void setValue(int newValue) {
        if (DEBUG) {
            System.out.println("In ConverterRangeModel setValue");
        }
        setDoubleValue((double)newValue);
    }

    public double getDoubleValue() {
        if (DEBUG) {
            System.out.println("In ConverterRangeModel getDoubleValue");
        }
        return value;
    }

    public void setDoubleValue(double newValue) {
        if (DEBUG) {
            System.out.println("In ConverterRangeModel setDoubleValue");
        }
        setRangeProperties(newValue, extent, minimum, maximum, isAdjusting);
    }

    public int getExtent() {
        return (int)extent;
    }

    public void setExtent(int newExtent) {
        //Do nothing.
    }

    public boolean getValueIsAdjusting() {
        return isAdjusting;
    }

    public void setValueIsAdjusting(boolean b) {
        setRangeProperties(value, extent, minimum, maximum, b);
    }

    public void setRangeProperties(int newValue,
                                   int newExtent,
                                   int newMin,
                                   int newMax,
                                   boolean newAdjusting) {
        System.out.println("In ConverterRangeModel setRangeProperties");
        setRangeProperties((double)newValue,
                           newExtent,
                           newMin,
                           newMax,
                           newAdjusting);
    }

    public void setRangeProperties(double newValue,
                                   int unusedExtent,
                                   int unusedMin,
                                   int newMax,
                                   boolean newAdjusting) {
        if (DEBUG) {
            System.out.println("setRangeProperties(): "
                                + "newValue = " + newValue
                                + "; newMax = " + newMax);
        }
        if (newMax <= minimum) {
            newMax = minimum + 1;
            if (DEBUG) {
                System.out.println("maximum raised by 1 to " + newMax);
            }
        }
        if (Math.round(newValue) > newMax) { //allow some rounding error
            newValue = newMax;
            if (DEBUG) {
                System.out.println("value lowered to " + newMax);
            }
        }

        boolean changeOccurred = false;
        if (newValue != value) {
            if (DEBUG) {
                System.out.println("value set to " + newValue);
            }
            value = newValue;
            changeOccurred = true;
        }
        if (newMax != maximum) {
            if (DEBUG) {
                System.out.println("maximum set to " + newMax);
            }
            maximum = newMax;
            changeOccurred = true;
        }
        if (newAdjusting != isAdjusting) {
            maximum = newMax;
            isAdjusting = newAdjusting;
            changeOccurred = true;
        }

        if (changeOccurred) {
            fireStateChanged();
        }
    }

    /* 
     * The rest of this is event handling code copied from 
     * DefaultBoundedRangeModel. 
     */
    public void addChangeListener(ChangeListener l) {
        listenerList.add(ChangeListener.class, l);
    }

    public void removeChangeListener(ChangeListener l) {
        listenerList.remove(ChangeListener.class, l);
    }

    protected void fireStateChanged() {
        Object[] listeners = listenerList.getListenerList();
        for (int i = listeners.length - 2; i >= 0; i -=2 ) {
            if (listeners[i] == ChangeListener.class) {
                if (changeEvent == null) {
                    changeEvent = new ChangeEvent(this);
                }
                ((ChangeListener)listeners[i+1]).stateChanged(changeEvent);
            }
        }
    }
}


import javax.swing.*; 
import javax.swing.text.*; 

import java.awt.Toolkit;
import java.text.*;

public class DecimalField extends JTextField {
    private NumberFormat format;

    public DecimalField(double value, int columns, NumberFormat f) {
        super(columns);
        setDocument(new FormattedDocument(f));
        format = f;
        setValue(value);
    }

    public double getValue() {
        double retVal = 0.0;

        try {
            retVal = format.parse(getText()).doubleValue();
        } catch (ParseException e) {
            // This should never happen because insertString allows
            // only properly formatted data to get in the field.
            Toolkit.getDefaultToolkit().beep();
            System.err.println("getValue: could not parse: " + getText());
        }
        return retVal;
    }

    public void setValue(double value) {
        setText(format.format(value));
    }
}


/*
 * 1.1+Swing version.
 */

import javax.swing.*;
import javax.swing.event.*;

public class FollowerRangeModel extends ConverterRangeModel
                                implements ChangeListener {
    ConverterRangeModel dataModel;

    public FollowerRangeModel(ConverterRangeModel dataModel) {
        this.dataModel = dataModel;
        dataModel.addChangeListener(this);
    }

    public void stateChanged(ChangeEvent e) {
        fireStateChanged();
    }

    public int getMaximum() {
        int modelMax = dataModel.getMaximum();
        double multiplyBy = dataModel.getMultiplier()/multiplier;
        if (DEBUG) {
            System.out.println("In FollowerRangeModel getMaximum");
            System.out.println("  dataModel.getMaximum = " + modelMax
                                + "; multiply by " + multiplyBy
                                + "; result: " + modelMax*multiplyBy);
        }
        return (int)(modelMax * multiplyBy);
    }

    public void setMaximum(int newMaximum) {
        dataModel.setMaximum((int)(newMaximum * 
                     (multiplier/dataModel.getMultiplier())));
    }

    public int getValue() {
        return (int)getDoubleValue();
    }

    public void setValue(int newValue) {
        setDoubleValue((double)newValue);
    }

    public double getDoubleValue() {
        return dataModel.getDoubleValue()
               * dataModel.getMultiplier()
               / multiplier;
    }

    public void setDoubleValue(double newValue) {
        dataModel.setDoubleValue(
                     newValue * multiplier
                     / dataModel.getMultiplier());
    }

    public int getExtent() {
        return super.getExtent();
    }

    public void setExtent(int newExtent) {
        super.setExtent(newExtent);
    }

    public void setRangeProperties(int value,
                                   int extent,
                                   int min,
                                   int max,
                                   boolean adjusting) {
        double multiplyBy = multiplier/dataModel.getMultiplier();
        dataModel.setRangeProperties(value*multiplyBy,
                                     extent, min, 
                                     (int)(max*multiplyBy),
                                     adjusting);
    }
}


import javax.swing.*; 
import javax.swing.text.*; 

import java.awt.Toolkit;
import java.text.*;
import java.util.Locale;

public class FormattedDocument extends PlainDocument {
    private Format format;

    public FormattedDocument(Format f) {
        format = f;
    }

    public Format getFormat() {
        return format;
    }

    public void insertString(int offs, String str, AttributeSet a) 
        throws BadLocationException {

        String currentText = getText(0, getLength());
        String beforeOffset = currentText.substring(0, offs);
        String afterOffset = currentText.substring(offs, currentText.length());
        String proposedResult = beforeOffset + str + afterOffset;

        try {
            format.parseObject(proposedResult);
            super.insertString(offs, str, a);
        } catch (ParseException e) {
            Toolkit.getDefaultToolkit().beep();
            System.err.println("insertString: could not parse: "
                               + proposedResult);
        }
    }

    public void remove(int offs, int len) throws BadLocationException {
        String currentText = getText(0, getLength());
        String beforeOffset = currentText.substring(0, offs);
        String afterOffset = currentText.substring(len + offs,
                                                   currentText.length());
        String proposedResult = beforeOffset + afterOffset;

        try {
            if (proposedResult.length() != 0)
                format.parseObject(proposedResult);
            super.remove(offs, len);
        } catch (ParseException e) {
            Toolkit.getDefaultToolkit().beep();
            System.err.println("remove: could not parse: " + proposedResult);
        }
    }
}


public class Unit {
    String description;
    double multiplier;

    Unit(String description, double multiplier) {
        super();
        this.description = description;
        this.multiplier = multiplier;
    }

    public String toString() {
        String s = "Meters/" + description + " = " + multiplier;
        return s;
    }
}


