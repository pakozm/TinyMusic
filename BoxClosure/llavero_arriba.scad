use <pcb_mascara.scad>
use <pcb_mascara2.scad>
use <gatos.scad>

/*
 *
 * El cubo mide 30x30x25, pero va roto en dos partes
 *
 */
 
module llavero_arriba() {

        union() {
                translate([14,14,20-8]) {
                    //translate([0,0,0]) pcb_mascara(1);
                    //translate([0,0,0]) pcb_mascara2(7);
                    //pcb_holes(40);
                }

            //translate([1.5,1.5,0]) cube(25,25,21);

            difference() {
                union() {
                    translate([15,30,11.5]) {
                        difference() {
                            cylinder(2,r=10,$fn=200);
                            translate([0,4,-1]) cylinder(4,r=3,$fn=200);
                        }
                    }
                    cube([30,30,23]);
                }
                translate([14,25,21]) cube([2,10,4]);
                
                translate([17,15,-1]) { scale(0.6,0.6,0.6) gatos(3.0); }
                /*
                translate([11,4,-1]) { cube([2,2,10]); }
                translate([11,4,-1]) { cube([2,10,10]); }                */
                translate([2,2,2]) cube([26,26,100]);
                translate([1,1,12]) cube([28,28,100]);

                translate([2+6,28-6,-40]) cylinder(120, r=2.2, $fn=200);
                translate([2+20,28-8,-40]) cylinder(120, r=3, $fn=200);
                

                // JOSEPA
                translate([14,0.5,9]) {
                    rotate([90,180,0]) {
                        linear_extrude(height = 1) {
                            text(text = "Josepa", font = "Liberation Sans:style=Bold", size = 5, halign = "center");
                        }
                    }
                }
                // Y PACO
                translate([14,0.5,17]) {
                    rotate([90,180,0]) {
                        linear_extrude(height = 1) {
                            text(text = "y Paco", font = "Liberation Sans:style=Bold", size = 5, halign = "center");
                        }
                    }
                }
                
                // 16-07-2016        
                translate([29.5,13,12.5]) {
                    rotate([90,150,90]) {
                        linear_extrude(height = 1) {
                            text(text = "16-07-2016", font = "Liberation Sans:style=Bold", size = 4, halign = "center");
                        }
                    }
                }
                
                // MINOR
                translate([0.5,14,9]) {
                    rotate([90,180,270]) {
                        linear_extrude(height = 1) {
                            text(text = "Minor", font = "Liberation Sans:style=Bold", size = 5, halign = "center");
                        }
                    }
                }
                // SWING
                translate([0.5,14,17]) {
                    rotate([90,180,270]) {
                        linear_extrude(height = 1) {
                            text(text = "Swing", font = "Liberation Sans:style=Bold", size = 5, halign = "center");
                        }
                    }
                }                

            }


        }
    }


llavero_arriba();
