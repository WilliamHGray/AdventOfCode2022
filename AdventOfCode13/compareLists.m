function[ordered] = compareLists(In1,In2)

if(size(In1,2)==0)
    s=size(In2,2);
    if(s==0)
        ordered=2;
    else
        ordered=1;
    end
else
    for i=1:size(In1,2)
        if size(In2,2)<i
            ordered=0;
            break
        end
        q=iscell(In1{i})+iscell(In2{i});
        if(q==0)
            if(In1{i}<In2{i})
                ordered=1;
                break
            elseif(In1{i}>In2{i})
                ordered=0;
                break
            end
        elseif(q==2)
            ordered=compareLists(In1{i},In2{i});
            if(ordered~=2)
                break
            end
        elseif(q==1)
            ordered=compareListCell(In1{i},In2{i});
            break
        else
            disp("Undefined")
        end
        ordered = 2;
    end
end
end