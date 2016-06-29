use <pcb_button.scad>
use <pcb_mascara.scad>
use <pcb_mascara2.scad>
use <pcb_holes.scad>
use <gato4.scad>

/*
 *
 * El cubo mide 30x30x25, pero va roto en dos partes
 *
 */

module llavero_abajo() {

    module base() {
            union() {
                difference() {
                    cube([30,30,2]);
                    translate([15,15,-1]) { scale([0.8,0.8,0.8]) gato4(2.0); }
                }
                // bisel interior
                difference() {
                    translate([1.2,1.2,2]) cube([27.4,27.4,10.7]);
                    difference() {
                        translate([2.6,2.6,2]) cube([24.5,24.5,90]);
                        rotate([0,0,45]) { translate([15,15,2.6]) cube([24,24,9.5]); }
                        translate([30,0,0]) { rotate([0,0,45]) { translate([15,15,2.6]) cube([24,24,9.5]); } }
                        translate([30,-46,0]) { rotate([0,0,45]) { translate([15,15,2.6]) cube([24,24,9.5]); } }
                    }
                }
    
                translate([15,15,2]) {
                    //translate([0,0,7]) pcb_mascara(1);
                    //translate([0,0,0]) pcb_mascara2(7);
                    //translate([-12+5.20,12-4.85,8]) cylinder(12, r=2.1, $fn=200);
                    //pcb_holes(40);
                }
    
            }
   }

   translate([0,0,0]) {
      base();
   }
}

llavero_abajo();
                        //translate([2.6,2.6,2.6]) cube([24.5,24.5,90]);
