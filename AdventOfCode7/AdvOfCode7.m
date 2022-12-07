A=fileread("AOC7.txt");
maxMem=70000000;
reqMem=30000000;
B=regexp(A,'\n','split');
pwd={};
layer=0;
prepwd = '';
[m,n]=size(B);
N={};
M=[];
allSizes=[];
someConst=10;
totalSize=0;
k=0;
for i=1:n
	C=B{i}
	if C(1)=='$' && C(3)=='c'
		if C(6)=='.'
			pwd(layer)='';
			layer=layer-1;
		else
			layer=layer+1;
			k=k+1;
			M(k)=i;
			N(k)={C(6:strlength(C)-1)};
			pwd(layer)={strcat(N{k},'/')};
			N(k)={strcat(prepwd,N{k},'/')};
		end
		prepwd='';
		for q=1:layer
			prepwd=strcat(prepwd,pwd{q});
		end
	end
end
dirs={}
for i = 1:k-1
	temp={};
	q=1;
	for k = (M(i)):(M(i+1))
		if B{j}(1)~='$'
			if B{j}(1)=='d'
				temp(q)=strcat(B{j}(1:4),{' '},N{i},B{j}(5:strlength(B{j})=1),'/');
			else
				temp(q)={B{j}(1:strlength(B{j})-1)};
			end
			q=q+1;
		end
	end
	[ts1,ts2]=size(temp);
	for l=ts2+1:someConst
		temp(l)={0};
	end
	dirs(i,:)=temp;
end
	i=k;
	temp={};
	q=1;
	for k = (M(i)):n)
		if B{j}(1)~='$'
			if B{j}(1)=='d'
				temp(q)=strcat(B{j}(1:4),{' '},N{i},B{j}(5:strlength(B{j})=1),'/');
			else
				temp(q)={B{j}(1:strlength(B{j})-1)};
			end
			q=q+1;
		end
	end
	[ts1,ts2]=size(temp);
	for l=ts2+1:someConst
		temp(l)={0};
	end
	dirs(i,:)=temp;
[unneeded,numOfDirs]=size(N);
for i=1:numOfDirs
	N{i};
	f=findSize(N{i},N,dirs);
	allSizes(i)=f;
	if f<=100000
		totalSize=totalSize+f;
	end
end
totalSize	%answer to part 1
spaceReq=maxMem-allSizes(1);
toDelete=reqMem-spaceReq;
greaterSizes=allSizes-toDelete;
greaterSizes(greaterSize<0)=nan;
smallest=min(greaterSizes);
smallest+toDelete	%answer to part 2