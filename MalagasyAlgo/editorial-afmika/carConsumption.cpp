/**
 * @author afmika
 * Problem : Car Consumption
 * AlgoMada Devfest Rookies Contest solution
 */

#include <bits/stdc++.h>
using namespace std;


int main() {
    // total fuel, total samples
    double F, T;
    cin >> F >> T;
    
    int period = 1;
    while (period <= T) {
        // R : the remaining fuel in the fuel tank (mL)
        // D : the driven distance so far (m)
        double R, D;
        cin >> R >> D;

        double dist_km = D / 1000.; // (m -> km)
        double elapsed_sec = period * 10.; // (sec)
        
        // * Remaining fuel
        double Rl = R / 1000.; // (mL -> L)
        
        // * The current trip duration (sec -> min)
        double M = elapsed_sec / 60.;
        
        // * The current fuel consumption
        // total used := total fuel - remaining fuel (L)
        double total_used_fuel = (F - R) / 1000.;   // (L)
        double C = total_used_fuel * 100. / dist_km; // (L / 100 km)
        
        // * The current avg the speed
        double speed = dist_km / elapsed_sec; // (Km / s)
        double S = speed * 3600.; // (Km / h)
        
        // * The remaining fuel autonomy
        double A = Rl * 100. / C;

        printf("%i %i %i %i %i\n", (int) Rl, (int) M, (int) C, (int) S, (int) A);

        period++;
    }
    return 0;
}