function getShapeFromString(s){
    if(s.charAt(0) != '{' || s.charAt(s.length-1) != '}')
        throw new Error('Format Error');
    s = s.substring(1, s.length - 1);
    s = s.split(';');
    if(s[0] == 'convex polygon'){
        return createConvexPolygon(s[1]);
    }
    else if (s[0] == 'circle') {
        var c = s[1] + ';' + s[2];
        return createCircle(c);
    }
    else{
        throw new Error('Not a shape');
    }
}
