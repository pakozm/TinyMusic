
// Module names are of the form poly_<inkscape-path-id>().  As a result,
// you can associate a polygon in this OpenSCAD program with the corresponding
// SVG element in the Inkscape document by looking for the XML element with
// the attribute id="inkscape-path-id".

// fudge value is used to ensure that subtracted solids are a tad taller
// in the z dimension than the polygon being subtracted from.  This helps
// keep the resulting .stl file manifold.
fudge = 0.1;

module poly_path20(h)
{
  scale([25.4/90, -25.4/90, 1]) union()
  {
    linear_extrude(height=h)
      polygon([[-42.690625,-42.690625],[42.690625,-42.690625],[42.690625,42.690625],[-42.690625,42.690625],[-42.690625,-42.690625]]);
  }
}

module poly_path24(h)
{
  scale([25.4/90, -25.4/90, 1]) union()
  {
    linear_extrude(height=h)
      polygon([[-42.690625,-42.690625],[42.690625,-42.690625],[42.690625,42.690625],[-42.690625,42.690625],[-42.690625,-42.690625]]);
  }
}

module poly_path16(h)
{
  scale([25.4/90, -25.4/90, 1]) union()
  {
    linear_extrude(height=h)
      polygon([[-42.690625,-42.690625],[42.690625,-42.690625],[42.690625,42.690625],[-42.690625,42.690625],[-42.690625,-42.690625]]);
  }
}

module pcb_mascara(h)
{

poly_path20(h);
poly_path24(h);
poly_path16(h);
}

pcb_mascara(1);
