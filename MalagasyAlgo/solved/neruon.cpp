#include <bits/stdc++.h>

using namespace std;
struct Layer {
    // basically a Neuron
    double w;
    double res;
    double in;
    Layer (double w) {
        this->res = 0;
        this->w = w;
    }
};

double r(double in) {
    return round(in * 100000) / 100000;
}


void feedfoward (double input, vector<Layer *> layers) {
    for (int i = 0; i < (int) layers.size(); i++) {
        Layer *layer = layers[i];
        layer->in = input;
        layer->res = layer->w * layer->in;
        input = layer->res;
    }
}

void backprop (double output, vector<Layer *> layers) {
    int n = (int) layers.size();
    double r = 0.1;
    double feed_out = layers[n - 1]->res;
    double y = output; 
    for (int i = n - 1; i >= 0; i--) {
        Layer *layer = layers[i];
        if (i == n - 1) {
            // last layer
            double an = layer->res;
            double an_1 = layer->in;
            layer->w -= r * an_1 * 2 * (an - y);
        } else {
            double an = feed_out;
            double ai_1 = layer->in;
            double p_wj = 1;
            for (int j = i + 1; j < n; j++)
                p_wj *= layers[j]->w;
            layer->w -= r * ai_1 * p_wj * 2 * (an - y);
        }
    }
} 

void print (vector<Layer * > layers) {
    int n = (int) layers.size();
    for (int i = 0; i < n; i++) {
        Layer *l = layers[i]; 
        cout << r(l->w);
        cout << (i + 1 == n ? "" : " ");
    }
}

void train (double input, double output, vector<Layer * > layers) {
    double d = INT_MAX;
    double e = 0.00001;
    int n = (int) layers.size();
    while (true) {
        feedfoward(input, layers);
        d = fabs(output - layers[n - 1]->res);
        backprop(output, layers);
        if (d > e) {
            print(layers);
            cout << "\n";
        } else
            break;
        cerr << " curr output = " << layers[n - 1]->res << "\n";
    }
}
  
int main () {
    double input, output, n;
    cin >> input >> output >> n;
    vector<Layer * > layers;
    for (int i = 0; i < n; i++) {
        double w;
        cin >> w;
        layers.push_back(new Layer(w));
    }
    train(input, output, layers);
    return 0;
}
