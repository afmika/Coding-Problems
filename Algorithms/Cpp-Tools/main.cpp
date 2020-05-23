
#include "afTools.h"

int main() {

    // test match
    cout << "Test match" << endl;
    vector<string> res_match = afTools::match_regex("[0-9]+", "Le numero de tel est 0330231843, son ID est ID:658");
    for ( auto s : res_match) {
        cout << s << endl;
    }

    // test split
    cout << "\nTest split" << endl;
    vector<string> res_split = afTools::split_regex("([ +,:]|-)+", "033  02-318:+43");
    for ( auto s : res_split) {
        cout << s << endl;
    }

    // test replace

    cout << "\nTest str <-> number" << endl;
    string temp = afTools::number_to_str( 3.0215 );
    double x = 54.123;
    cout
        << afTools::number_to_str( 3.0215 ) << " "
        << afTools::number_to_str( 45678 ) << " "
        << afTools::number_to_str( 17.12f ) << " "
        << afTools::number_to_str( x ) << " "
        << afTools::str_to_float("2.65") << " "
        << afTools::str_to_int("87")
    << endl;
    return 0;
}
