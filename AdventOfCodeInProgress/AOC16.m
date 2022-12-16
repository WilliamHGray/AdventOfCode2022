tic
A=fileread("AOC16.txt");
B=regexp(A,'\n','split');
for i=1:size(B,2)-1
    B{i}=strtrim(B{i});
end
running = 0;
names={};
weights=[];
cave=graph;
numOfValves=i;
j=1;
for i=1:size(B,2)
   f=regexp(B{i},' has','split'); 
   f=regexp(f{1},' ','split');
   g=regexp(B{i},';','split'); 
   g=regexp(g{1},'=','split');
   names(j)=f(2);
   cave=addnode(cave,f(2));
   weights(j)=str2num(g{2});
   
   if(weights(j)<8)
      weights(j)=0;
   end
   
   j=j+1;
end
for i=1:size(B,2)
    f=regexp(B{i},'to valve','split');
    f=regexp(f{2},', ','split');
    if(f{1}(1)=='s')
    	f{1}=f{1}(3:4);
    elseif(f{1}(1)==' ')
        f{1}=f{1}(2:3);
    end
    for j=1:size(f,2)
        if(~findedge(cave,names(i),f{j}))
            cave=addedge(cave,names(i),f{j});
        end
    end
end

time=30;
start='AA';
index=find(strcmp(names,start));
total=nextStep(time,index,cave,names,weights)

toc