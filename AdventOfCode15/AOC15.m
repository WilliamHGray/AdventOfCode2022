A=fileread("AOC15.txt");
B=regexp(A,'\n','split');
for i=1:size(B,2)-1
    B{i}=strtrim(B{i});
end

someConstant=2000000;
%someConstant=10;
%xMax=20;
%yMax=20;
xMax=4000000;
yMax=4000000;
%beacon=zeros(yMax+1,xMax+1);
bSet=[];
u=1;
xCoords=[];
bCoords=[];
cSet=[];
j=1;
q=1;
l=1;
for i=1:size(B,2)
    [x1,x2,y1,y2]=extractCoords(B{i});
    if(y2==someConstant&&~ismember(x2,bCoords))
        bCoords(q)=x2;
        q=q+1;
    end
    xdist=abs(x1-x2);
    ydist=abs(y1-y2);
    man=xdist+ydist;
    yman=abs(y1-someConstant);
    xman=man-yman;
    if (xman>0)
        c1=x1-xman;
        c2=x1+xman;
        cSet(l,:)=[i x1 y1 x2 y2 c1 c2];
        l=l+1;
        xCoords(j:j+c2-c1)=c1:c2;
        j=j+c2-c1+1;
    end
    bSet(u,:)=[man x1 y1];
    u=u+1;
end
size(unique(xCoords),2)-size(bCoords,2)
i=1;
j=1;
while i<yMax
    j=1;
    while j<xMax
        t=0;
        for k=1:size(bSet,1)
            x=bSet(k,2);
            y=bSet(k,3);
            man=bSet(k,1);
            xdiff=abs(j-x);
            ydiff=abs(i-y);
            if(xdiff+ydiff<=man)
                xman=man-ydiff;
                j=xman+x+1;
                t=1;
            end
        end
        if(t==0)
            [j i]
            j*4000000+i
            break
        end
    end
    if(t==0)
        break
    else
        i=i+1;
    end
end