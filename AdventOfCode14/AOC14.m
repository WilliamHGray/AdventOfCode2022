A=fileread("AOC14.txt");
B=regexp(A,'\n','split');
total=0;
total2=0;
ymax=1;
for i=1:size(B,2)-1
    B{i}=strtrim(B{i});
end
start = [1 500];
Z=zeros(201,800);
for i=1:size(B,2)
    wall=B{i};
    C=regexp(B{i},'->','split');
    D=[];
    for j=1:size(C,2)
        [x,y]=getCoords(C{j});
        D(j,:)=[x y];
        if y>ymax
            ymax=y;
        end
    end
    for j=2:size(D)
        if D(j,1)==D(j-1,1)
            x=D(j,1);
            y1=D(j,2);
            y2=D(j-1,2);
            if y1>y2
                Z(y2:y1,x)=1;
            else
                Z(y1:y2,x)=1;
            end
            
        else
            y=D(j,2);
            x1=D(j,1);
            x2=D(j-1,1);
            if x1>x2
                Z(y,x2:x1)=1;
            else
                Z(y,x1:x2)=1;
            end
            
        end
    end
end

Z1=Z;
x=start(2);
y=start(1);
term=1;
while term==1
   x=start(2);
   y=start(1);
   [s, t]=sandFall(x,y,Z1); 
   if(t==size(Z1,1))
       term=0;
   else
       Z1(t,s)=1;
       total=total+1;
   end
end
total

Z2=Z;
Z2(ymax+2,:)=1;
x=start(2);
y=start(1);
term=1;
while term==1
   x=start(2);
   y=start(1);
   [s, t]=sandFall(x,y,Z2); 
   if(t==y && s==x)
       Z2(t,s)=2;
       total2=total2+1;
       term=0;
   else
       Z2(t,s)=2;
       total2=total2+1;
   end
end
total2
