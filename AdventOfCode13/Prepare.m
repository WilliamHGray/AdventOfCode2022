function[instr] = Prepare(in1)
    if size(in1,2)>2
    q={};
    it1=2;
    while(it1<size(in1,2))
        if(in1(it1)=='[')
            layer=1;
            start=it1;
            while((layer>0))
                it1=it1+1;
                if(in1(it1)=='[')
                    layer=layer+1;
                elseif(in1(it1)==']')
                    layer=layer-1;
                end   
            end
            q(end+1)={Prepare(in1(start:it1))};
            it1=it1+2;
        else
            out=[];
            start=it1;
            while(in1(it1)~=','&&in1(it1)~=']')
               out(end+1)=in1(it1);
               it1=it1+1;
            end
            attempt=in1(start:it1-1);
            it1=it1+1;
            q(end+1)={str2num(attempt)};
            
        end
        
    end
    instr=q;
    else
        instr={};
    end
end