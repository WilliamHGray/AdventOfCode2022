A=fileread("AOC13.txt");
B=regexp(A,'\n','split');
for i=1:size(B,2)
    B{i}=B{i}(1:length(B{i})-1);
end
numPairs = ceil(size(B,2)/3);
total=0;
arrPairs=[];
j=0;
for i=1:numPairs
    
    I1=Prepare(B{(3*i)-2});
    I2=Prepare(B{(3*i)-1});
    
    if(compareLists(I1,I2))
        j=j+1;
        arrPairs(j)=i;
        i;
        total=total+i;
    end
    
    %{
    I1=stringToNumArray(B{(3*i)-2});
    I2=stringToNumArray(B{(3*i)-1});
    if(compareArrs(I1,I2))
        total=total+i;
    end
    %}
end
total
    