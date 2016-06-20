
// Module names are of the form poly_<inkscape-path-id>().  As a result,
// you can associate a polygon in this OpenSCAD program with the corresponding
// SVG element in the Inkscape document by looking for the XML element with
// the attribute id="inkscape-path-id".

// fudge value is used to ensure that subtracted solids are a tad taller
// in the z dimension than the polygon being subtracted from.  This helps
// keep the resulting .stl file manifold.
fudge = 0.1;

module poly_path14(h)
{
  scale([25.4/90, -25.4/90, 1]) union()
  {
    linear_extrude(height=h)
      polygon([[23.247500,21.596250],[22.941387,23.114434],[22.106406,24.354531],[20.867598,25.190801],[19.350000,25.497500],[17.833125,25.190801],[16.594688,24.354531],[15.759844,23.114434],[15.453750,21.596250],[15.759844,20.081484],[16.594688,18.842812],[17.833125,18.006797],[19.350000,17.700000],[20.867598,18.006797],[22.106406,18.842812],[22.941387,20.081484],[23.247500,21.596250]]);
  }
}

module poly_path16(h)
{
  scale([25.4/90, -25.4/90, 1]) union()
  {
    linear_extrude(height=h)
      polygon([[-15.448750,-21.601250],[-15.755645,-20.084375],[-16.592344,-18.845937],[-17.832871,-18.011094],[-19.351250,-17.705000],[-20.868125,-18.011094],[-22.106563,-18.845937],[-22.941406,-20.084375],[-23.247500,-21.601250],[-22.941406,-23.118652],[-22.106563,-24.357031],[-20.868125,-25.191582],[-19.351250,-25.497500],[-17.832871,-25.191582],[-16.592344,-24.357031],[-15.755645,-23.118652],[-15.448750,-21.601250]]);
  }
}

module pcb_holes(h)
{

poly_path14(h);
poly_path16(h);
}

pcb_holes(3);
