/*
 * @author afmika
 * github.com/afmika
 * email afmichael73@gmail.com
 **/
 
module.exports = class Hashmap {

    constructor() {
        this.key = [];
        this.value = [];
    }

    set (key, value) {
        let index = 0;
        let that = this;
        this.key.forEach(k => {
            if(key.equals) {
                if(key.equals(k)) {
                    // that.key[ index ] = key;
                    that.value[ index ] = value;
                    return;
                }
            } else if(k == key) {
                // that.key[ index ] = key;
                that.value[ index ] = value;
                return;
            }
            index++;
        });

        if(index == this.key.length) {
            this.key.push( key ); 
            this.value.push( value ); 
        }
    }

    forEach (fun) {
        let index = 0, that = this;
        this.key.forEach(k => {
            fun(k, that.value [ index ]);
            index++;
        });
    }

    get (key) {
        for (let index = 0; index < this.key.length; index++) {
            const item = this.key[index];
			if(key.equals) {
				if(key.equals(item)) {
					return this.value[ index ];	
				}
			} else if(item == key) {
				 return this.value[ index ];
			}
        }
        return null;
    }

    equals (hashmap) {
        let are_equals = true;
        if( hashmap.key.length != this.key.length) {
            return false;
        }
        this.forEach((key, value) => {
            let v = hashmap.get(key);
            if(v == null) {
                are_equals = false;
                return;
            }
            if(v.equals) {
                are_equals = are_equals && v.equals(value);
            } else {
                are_equals = are_equals && v == value;
            }
        });
        return are_equals;
    }
}