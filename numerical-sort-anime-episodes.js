function numericalSort (list, reverse = false) {
    let fetchNumeric = str => {
        let match = str.match(/[0-9]+/gi);
        return match == null ? [] : match.map(q => parseInt(q));
    };

    let order = (a, b) => {
        if (reverse) [a, b] = [b, a];
        let numa = fetchNumeric (a);
        let numb = fetchNumeric (b);
        let min_idx = Math.min(numa.length, numb.length);
        for (let i = 0; i < min_idx; i++) {
            let diff = numa[i] - numb[i];
            if (diff != 0)
                return diff;
        }
        return reverse ? 1 : -1;
    };


    return list.sort(order);
}


let list = ['dsad_6', 'op_1_1', 'op_3_3.2', 'op_1_1.4'];

numericalSort(list).forEach (val => {
    console.log(val);
});

