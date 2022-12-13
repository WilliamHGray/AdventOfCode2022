function[ordered] = compareListCell(In1,In2)
if(iscell(In1))
    if(size(In1,2)>0)
        if(iscell(In1{1}))
            ordered=compareListCell(In1{1},In2);
        else
            if(In1{1}<In2)
                ordered=1;
            else
                ordered=0;
            end
        end
    else
        ordered=1;
    end
elseif(iscell(In2))
    if(size(In2,2)>0)
        if(iscell(In2{1}))
            ordered=compareListCell(In1,In2{1});
        else
            if(In1<=In2{1})
                ordered=1;
            else
                ordered=0;
            end
        end
    else
        ordered=0;
    end
end