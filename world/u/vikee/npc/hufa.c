//created by vikee
//2000.10
inherit SSERVER;
int cast(object me, object target)
{
        int invocation_time,lvl,lvl2;
        object soldier;
        lvl=me->query_skill("dengxian-dafa",1);
        if( lvl<40) return notify_fail("�㻹�����������а���������\n");
        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в����ٻ�������\n");
        invocation_time=60+(200-(int)me->query_skill("spells"));
        if(invocation_time<30) invocation_time=30;
        if((time()-me->query("last_invocation"))<invocation_time)
            return notify_fail("��սй����������Ƕ�����з��ˣ�\n");
        if( (int)me->query("mana") < 150 )
                return notify_fail("��ķ��������ˣ�\n");
        if( (int)me->query("sen") < 80 )
                return notify_fail("��ľ����޷����У�\n");
        message_vision("$N�૵����˼������\n", me);
        me->add("mana", -150);
        me->receive_damage("sen", 80);
        if( random(me->query("max_mana")) < 250 ) {
                message("vision", "����ʲôҲû�з�����\n",
environment(me));
                return 1;
        }
        seteuid(getuid());
        if ( lvl >=300)
        {
                soldier = new("/obj/npc/xueshanhufa6");
        }
        else if ( lvl >=210)
        {
                soldier = new("/obj/npc/xueshanhufa3");
        }
        else if ( lvl >= 160)
        {
                soldier = new("/obj/npc/xueshanhufa3");
        }
        else if ( lvl >= 120)
        {
                soldier = new("/obj/npc/xueshanhufa2");
        }
        else if ( lvl >= 80)    
        {
                soldier = new("/obj/npc/xueshanhufa2");
        }       
        else    soldier = new("/obj/npc/xueshanhufa1");
        soldier->move(environment(me));
        soldier->invocation(me);
        soldier->set_temp("invoker",me);
        me->set("last_invocation",time());
        me->start_busy(2+random(2));
        return 8+random(5);
}