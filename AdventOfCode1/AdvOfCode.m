A=fileread("AOC1.txt");
B=regexp(A,'\n','split');

[j,k]=size(B);
max1=0;
max2=0;
max3=0;
temp=0;
for i = 1:k
	D=str2num(B{i});
	[m,n]=size(B{i});
	if(floor(D)==D)
		temp=temp+D;
	else
		if(temp>max3)
			if(temp>max2)
				if(temp>max1)
					max3=max2;
					max2=max1;
					max1=temp;
				else
					max3=max2;
					max2=temp;
				end
			else
				max3=temp;
			end
		end
		temp=0;
	end
end
max1
max1+max2+max3
		