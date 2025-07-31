#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;


class State {
public:
    double x; 

    State(double val = 0) : x(val) {}

    double getValue() const {
        // Objective function(minimize)
        return -1.0 * (x * x); 
    }



    State getRandomSuccessor() const {
        double delta = ((rand() % 2001) - 1000) / 1000.0; 
        return State(x + delta);
    }

    void print() const {
        cout << "x = " << x << ", f(x) = " << -getValue() << endl;
    }
};


double schedule(int t) {
    if (t == 0) return 1.0;
    return 1000.0 / (t); 
}



State simulatedAnnealing(State initialState) {
    State current = initialState;
    int t = 1;

    while (true) {
        double T = schedule(t);
        if (T == 0.0) {
            return current;
        }

        State next = current.getRandomSuccessor();
        double deltaE = next.getValue() - current.getValue();

        if (deltaE > 0) {
            current = next;
        } else {
            double probability = exp(deltaE / T);
            double randProb = ((double) rand()) / RAND_MAX;
            if (randProb < probability) {
                current = next;
            }
        }

        t++;

        if (t % 1000 == 0) {
            cout << "Step " << t << " -> ";
            current.print();
        }

       

        
        if (t > 10000) break;
    }

    return current;
}


int main() {
    srand(time(0)); 

    cout << "Simulated Annealing for minimizing f(x) = x^2\n";

    double initialX;
    cout << "Enter initial value of x: ";
    cin >> initialX;

    State initial(initialX);
    cout << "Initial state:\n";
    initial.print();

    State result = simulatedAnnealing(initial);

    cout << "\nFinal result:\n";
    result.print();

    return 0;
}

