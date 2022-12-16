function[total]=nextStep(time,ind,caves,names,weights)
if time~=0
    max=0;
    currNode=names{ind};
    for i=find(weights)
        if time==30
            i
        end
        remainder=0;
        nextNode=names{i};
        q=distances(caves,currNode,nextNode);
        if(q>0&&q<12)
            t=time;
            w=weights;
            t=t-q-1;
            remainder=t*weights(i);
            w(i)=0;
            remainder=remainder+nextStep(t,i,caves,names,w);
        end
        if max<remainder
            max=remainder;
        end
    end
    total=max;
else
    total=0;
end
end