void find_nearest_lowest(t_general *mother)
{
    int i;

    i = 0;
    mother->stack_b.nearest = i;
    while( i < mother->stack_b.len)
    {
        if (mother->stack_b.data[i] < mother->stack_a.data[0])
        {
            if (mother->stack_a.data[0] - mother->stack_b.data[mother->stack_b.nearest] > mother->stack_a.data[0] - mother->stack_b.data[i])
                mother->stack_b.nearest = i;
            i++;
        }
    }
}

void arrange_stack_b(t_general *mother)
{
    find_nearest_lowest(mother);
    if (mother->stack_b.nearest > mother->stack_b.len / 2)
    {
        while (mother->stack_b.nearest > 0)
        {
            rb_operation(mother);
            mother->stack_b.nearest--;
        }
    }
    else
    {
        while (mother->stack_b.nearest <= mother->stack_b.len)
        {
            rrb_operation(mother);
            mother->stack_b.nearest++;
        }
    }
    
}