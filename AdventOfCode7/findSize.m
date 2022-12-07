function[out]=findsize(CurrDir,DirNames,Dirs,position)
	sum = 0;
	pos = find(strcmp(CurrDir,DirNames));
	children=Dirs(pos,:);
	for i=1:10
		c=children{i};
		if c==0
			continue
		elseif c(1)=='d'
			sum=sum+findSize(c(5:strlength(c)),DirNames,Dirs,pos);
		else
			sum=sum+str2num(c(1:strfind(c,' ')));
		end
	end
	out1=sum;
end