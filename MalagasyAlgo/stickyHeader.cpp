int stickyHeader(int pageYOffset, int tableOffsetTop, int tableHeight, vector<int> breadcrumbs) {
    int yscroll = pageYOffset;
    int ytab = tableOffsetTop;
    int height = tableHeight;
    int b_offset = 0;
    for (int n : breadcrumbs) 
        b_offset += n;
    if ( yscroll + b_offset > ytab)
        if (ytab + height >  yscroll + b_offset )
            return b_offset;
    return -1;
}
