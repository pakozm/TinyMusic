use <llavero_arriba.scad>
use <llavero_abajo.scad>
use <ISOThread.scad>

translate([-30,0,0]) {
    llavero_arriba();
}

translate([30,0,0]) {
    llavero_abajo();
}

//hex_bolt(4,8);                                              // make an M10 x 16 ISO bolt
//hex_nut(10);                                                  // make an M10 ISO nut
//hex_bolt(8,16);                                               // make an M8 x 16 ISO bolt
//hex_nut(8);                                                   // make an M8 ISO nut
//hex_bolt(6,12);                                               // make an M6 x 12 ISO bolt
//hex_nut(6);                                                   // make an M6 ISO nut
//thread_out(8,16);                                     // make an M8 x 16 ISO thread
//thread_out_centre(8,16);                              // make a centre for an M8 x 16 ISO thread
//thread_out_pitch(8,16,1.0);                   // make an M8 x 16 thread with 1 mm pitch
//thread_out_centre_pitch(8,16,0.5);    // make the centre for an M8 x 16 thread with 1 mm pitch
//thread_in(8,10);                                              // make an M8 x 10 ISO thread
//thread_in_ring(8,10,2);                               // make a ring to enclose an M8 x 10 ISO thread with thickness 2 mm
//thread_in_pitch(8,10,1.0);                    // make an M8 x 10 thread with 1mm pitch
