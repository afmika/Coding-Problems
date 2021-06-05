// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem

int designerPdfViewer(vector<int> h, string word) {
    int nax = -1;
    for (char c : word) {
        // all lowercases
        nax = max(nax, h[c - 'a']);
    }
    return nax * word.size();
}