function[x1,x2,y1,y2] = extractCoords(string)
    B=regexp(string,':','split');
    C=regexp(B,'x=','split');
    in1=C{1}{2};
    in2=C{2}{2};
    in1=regexp(in1,', y=','split');
    in2=regexp(in2,', y=','split');
    x1=str2num(in1{1});
    x2=str2num(in2{1});
    y1=str2num(in1{2});
    y2=str2num(in2{2});
end