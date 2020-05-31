#include <iostream>
#include <stdlib.h>

#include "gnuploter.hpp"

int main() {
    plt_writer p("hoge.plt");

    p.write_command("plot sin(x)");
    p.write_command("pause -1");
    p.run();

    return 0;
}

