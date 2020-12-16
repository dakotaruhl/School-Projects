/**
 * @author Petr (http://www.sallyx.org/)
 */
package Chapter2StateMachines.MinersSonOwnedStates;

import common.Messaging.Telegram;
import Chapter2StateMachines.MinersSon;
import Chapter2StateMachines.MinersWife;
import Chapter2StateMachines.State;
import static common.misc.utils.*;
import static common.misc.ConsoleUtils.*;
import static common.Time.CrudeTimer.*;
import static common.windows.*;
import static Chapter2StateMachines.MessageTypes.*;
import static Chapter2StateMachines.EntityNames.*;

public class SonsGlobalState extends State<MinersSon> {

    static final SonsGlobalState instance = new SonsGlobalState();

    private SonsGlobalState() {
    }

    //copy ctor and assignment should be private
    @Override
    protected Object clone() throws CloneNotSupportedException {
        throw new CloneNotSupportedException("Cloning not allowed");
    }

    public static SonsGlobalState Instance() {
        return instance;
    }

    @Override
    public void Enter(MinersSon son) {
    }

    @Override
    public void Execute(MinersSon son) { 
    }

    @Override
    public void Exit(MinersSon son) {
    }

    @Override
    public boolean OnMessage(MinersSon son, Telegram msg) {
        SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

        switch (msg.Msg) {
            case Msg_HiHoneyImHome: {
                cout("\nMessage handled by " + GetNameOfEntity(son.ID()) + " at time: "
                        + Clock.GetCurrentTime());

                SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

                cout("\n" + GetNameOfEntity(son.ID())
                        + ": Hi Dad! Let me see what your doin'");

                son.GetFSM().ChangeState(Follow.Instance());
            }

            return true;

        }//end switch

        return false;
    }
}