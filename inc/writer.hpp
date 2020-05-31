#ifndef IG_GNUPLOTER_HPP
#define IG_GNUPLOTER_HPP

#include <vector>
#include <fstream>
#include <string>

class plt_writer {
    std::string file_name;
    std::ofstream plt_file;

public:
    plt_writer(std::string fname) : file_name(fname), plt_file(fname) { }

    enum terminal_type { png
                       , eps
                       , x11 // windows or x11
                       };
    enum draw_style { lines         // line
                    , points        // point
                    , linespoints   // line and point
                    , impulses      // impulse
                    , dots          // dot
                    , steps
                    , fsteps
                    , histeps
                    , boxes
                    };
    enum key_option { left
                    , right
                    , top
                    , bottom
                    , outside
                    , below
                    };

    void set_xrange(double l, double r) { } // set xrange [$l:$r]
    void set_yrange(double l, double r) { } // set yrange [$l:$r]
    void set_size(double x_scale, double y_scale) { } // set size $x_scale $y_scale
    void set_size(double ratio) { } // set size ratio $ratio
    void set_samples(std::size_t s) { } // set samples $s
    void set_logscale_y(double b = 10.0) { } // set logscale y
    void set_logscale_x(double b = 10.0) { } // set logscale x
    void unset_logscale() { } // unset logscale
    void set_xtics(double start, double d, double end) { } // set xtics $start, $d, $end
    void set_xtics(double start, double d) { } // set xtics $start, $d
    void set_xtics(double d) { } // set xtics $d
    void set_x2tics(double start, double d, double end) { } // set x2tics $start, $d, $end
    void set_x2tics(double start, double d) { } // set x2tics $start, $d
    void set_x2tics(double d); // set x2tics $d
    void set_ytics(double start, double d, double end) { } // set ytics $start, $d, $end
    void set_ytics(double start, double d) { } // set ytics $start, $d
    void set_ytics(double d) { } // set xtics $d
    void set_y2tics(double start, double d, double end) { } // set y2tics $start, $d, $end
    void set_y2tics(double start, double d) { } // set y2tics $start, $d
    void set_y2tics(double d) { } // set y2tics $d
    void set_mini_xtics(double d) { } // set mxtics $d
    void set_mini_x2tics(double d) { } // set mx2tics $d
    void set_mini_ytics(double d) { } // set mytics $d
    void set_mini_y2tics(double d) { } // set my2tics $d
    void set_title(std::string title, double dx = 0.0, double dy = 0.0) { } // set title $title $dx, $dy
    void set_terminal(terminal_type t, std::string output_name = "") { } // set terminal $t; set output $output_name
    void set_key(key_option o) { } // set key $o
    void set_key(double x, double y) { } // set key $x, $y
    void set_keytitle(std::string title) { } // set key title $title
    void unset_key() { } // unset key
    void set_margin(double left, double right, double top, double bottom) { } // set lmargin $l; set rmargin $r; set tmargin $t; set bmargin $b;
    void unset_left_margin() { } // unset lmargin
    void unset_right_margin() { } // unset rmargin
    void unset_top_margin() { } // unset tmargin
    void unset_bottom_margin() { } // unset bmargin
    void set_offsets(double left, double right, double top, double bottom) { } // set offsets $l $r $t $b
    void unset_offsets(); // unset offsets
    void plot() { } // fname, using, with
    void replot() { } // fname, using, with
    void splot() { } // fname, using, with, range

    void write_command(std::string cmd) {
        plt_file << cmd << std::endl;
    }
    void write_commands(std::vector<std::string> cmds) {
        for (auto itr = cmds.begin(); itr != cmds.end(); itr++)
            write_command(*itr);
    }
    void run() {
        std::string cmd = "gnuplot " + file_name;
        system(cmd.c_str());
    }
};

#endif

