function[x,y]=getCoords(in)
    in=in(find(~isspace(in)));
    q=regexp(in,',','split');
    x=str2num(q{1});
    y=str2num(q{2})+1;
end