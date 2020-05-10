function minimumRemove(text1, text2) {
    if (text2 == '' || text1.length < text2.length)
        return text1.length;
    if (text1.includes(text2)) {
        text1 = text1.replace(new RegExp(text2, "gi"), '0');
        text1 = text1.split("0");
        let removes = 0;
        console.log(text1);
        for (let i = 0; i < text1.length; i++) {
            if (text1[i] != '') {
                removes += text1[i].length;
            }
        }
        return removes;
    }
    return text1.length;
}

console.log( minimumRemove("abyab", "adsadaddab") );