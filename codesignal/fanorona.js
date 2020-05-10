function toCell(pos, width, height) {
    pos = pos - 1;
    let r = Math.floor( pos / width ),
        c = (pos - r * width);
    return {row : r, col : c};
}

function isValid(cell, width, height) {
    return cell.row >= 0 && cell.row < height && cell.col >= 0 && cell.col < width; 
} 

function fanoronaXYValidator(positionDepart, positionCible, tailleGrille) {
    let width = 9, height = tailleGrille / 9;
    let depart = toCell( positionDepart, width, height);
    let cible = toCell( positionCible, width, height );

    if ( !isValid(depart, width, height) || !isValid(cible, width, height)) {
        return [0, 0, 0, 0, 0];
    }

    let dy = cible.row - depart.row;
    let dx = cible.col - depart.col;
    let is_near = depart.row == cible.row || depart.col == cible.col
                || Math.abs(dy / dx) == 1;
    let is_valid = false;

    let ortho = positionDepart % 2 == 0;
    let diag = false;
    if ( ! ortho ) {
        ortho = true;
        diag = true;
    } 
	
	if (ortho && diag && is_near) {
		return [depart.row, depart.col, cible.row, cible.col, 1];
	}
	
	// ortho	
    let orthocheck = ortho && (depart.row == cible.row || depart.col == cible.col)
    return [depart.row, depart.col, cible.row, cible.col, orthocheck && is_near ? 1 : 0];
}
/*
positionDepart: 9
positionCible: 18
tailleGrille: 18
*/
console.log( fanoronaXYValidator(45, 35, 45) )