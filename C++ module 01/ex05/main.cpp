#include "Harl.hpp"

int main() {
    Harl harl;
    harl.complain("DEBUG");    // Should print "Debug mode on"
    // harl.complain("INFO");     // Should print "Information mode"
    // harl.complain("WARNING");  // Should print "Warning mode"
    // harl.complain("ERROR");    // Should print "Error mode"
    // harl.complain("UNKNOWN");  // Should print "khroj t9awed"

    return 0;
}