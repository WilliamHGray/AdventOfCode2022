A=fileread("AOC13.txt");
B=regexp(A,'\n','split');
for i=1:size(B,2)
    B{i}=B{i}(1:length(B{i})-1);
end
numPairs = ceil(size(B,2)/3);
total=0;
arrPairs=[];
j=0;
C={};
k=1;
for i=1:numPairs
    
    I1=Prepare(B{(3*i)-2});
    I2=Prepare(B{(3*i)-1});
    C(k)={I1};
    k=k+1;
    C(k)={I2};
    k=k+1;
    if(compareLists(I1,I2))
        j=j+1;
        arrPairs(j)=i;
        i;
        total=total+i;
    end

end
total

C(k)={Prepare('[2]')};
k=k+1;
C(k)={Prepare('[6]')};
sorted=0;
j=0;
while(sorted==0)
    j=j+1;
    sorted=1;
    for i=2:size(C,2)
        if(compareLists(C{i-1},C{i})==0)
            temp = C{i};
            C{i}=C{i-1};
            C{i-1}=temp;
            sorted=0;
        end
    end
    if (rem(j,10)==0)
        j
    end
    if j==1000
        sorted=1;
    end
end

for i=1:size(C,2)
    if isequal(C{i},{[2]})
        firstPos=i
    elseif isequal(C{i},{[6]})
        secondPos=i
    end
end
firstPos*secondPos