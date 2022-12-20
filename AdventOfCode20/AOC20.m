A=fileread("AOC20.txt");
B=regexp(A,'\n','split');
inputs=[];
for i=1:size(B,2);
    inputs(i)=str2num(B{i});
end
shifts=inputs*811589153;
m=size(inputs,2);
pos=[];
for i=1:m
    pos(i)=i;
end
%{
for i=1:m

    newPos=mod(inputs(i)+pos(i),m-1);
    start=pos(i);
    if newPos==0
        newPos=m-1;
    end
    if newPos<start
        pos1=pos<start;
        pos2=pos>=newPos;
        pos3=pos1&pos2;
        pos(pos3)=pos(pos3)+1;
        pos(i)=newPos;
    elseif newPos>start
        pos1=pos>start;
        pos2=pos<=newPos;
        pos3=pos1&pos2;
        pos(pos3)=pos(pos3)-1;
        pos(i)=newPos;
    end
    
    
end

out=[];
for i=1:m
    out(i)=inputs(find(pos==i));
end

zPos=pos(find(~inputs));
encrypts=[];
for i=1:3
    encrypts(i)=mod(zPos+1000*i,m);
    if encrypts(i)==0
        encrypts(i)=encrypts(i)+m;
    end
end
sum(out(encrypts))
%}
for l =1:10
for i=1:m

    newPos=mod(shifts(i)+pos(i),m-1);
    start=pos(i);
    if newPos==0
        newPos=m-1;
    end
    if newPos<start
        pos1=pos<start;
        pos2=pos>=newPos;
        pos3=pos1&pos2;
        pos(pos3)=pos(pos3)+1;
        pos(i)=newPos;
    elseif newPos>start
        pos1=pos>start;
        pos2=pos<=newPos;
        pos3=pos1&pos2;
        pos(pos3)=pos(pos3)-1;
        pos(i)=newPos;
    end
    
    
end

end

out=[];
for i=1:m
    out(i)=shifts(find(pos==i));
end

zPos=pos(find(~shifts));
encrypts=[];
for i=1:3
    encrypts(i)=mod(zPos+1000*i,m);
    if encrypts(i)==0
        encrypts(i)=encrypts(i)+m;
    end
end
sum(out(encrypts))


