/**
 * @author Petr (http://www.sallyx.org/)
 */
package Chapter2StateMachines.MinersSonOwnedStates;

import common.Messaging.Telegram;
import Chapter2StateMachines.MessageTypes;
import Chapter2StateMachines.MinersSon;
import Chapter2StateMachines.State;
import static Chapter2StateMachines.EntityNames.*;
import static common.misc.ConsoleUtils.*;
import static common.windows.*;
import static Chapter2StateMachines.MessageDispatcher.*;
import static common.Time.CrudeTimer.*;

class Follow extends State<MinersSon> {

    public static final Follow instance = new Follow();

    public Follow() {
    }

    //copy ctor and assignment should be private
    @Override
    protected Object clone() throws CloneNotSupportedException {
        throw new CloneNotSupportedException("Cloning not allowed");
    }

    public static Follow Instance() {
        return instance;
    }

    @Override
    public void Enter(MinersSon son) {
        //if not already following start following
        if (!son.Following()) {
            cout("\n" + GetNameOfEntity(son.ID()) + ": Following you around!");

            //send a delayed message myself so that I know when to take the stew
            //out of the oven
            Dispatch.DispatchMessage(1.5, //time delay
                    son.ID(), //sender ID
                    son.ID(), //receiver ID
                    MessageTypes.Msg_DoneFollowing, //msg
                    NO_ADDITIONAL_INFO);

            son.SetFollowing(true);
        }
    }

  

    @Override
    public void Exit(MinersSon son) {
        SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        cout("\n" + GetNameOfEntity(son.ID()) + ": Dunno wat to do! See yall later");
    }

    
    @Override
    public void Execute(MinersSon son) {
        cout("\n" + GetNameOfEntity(son.ID()) + ": I wonder where my toys went.");
    }
    
    
    @Override
    public boolean OnMessage(MinersSon son, Telegram msg) {
        SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_BLUE);

        switch (msg.Msg) {
            case Msg_DoneFollowing: {
                cout("\nMessage received by " + GetNameOfEntity(son.ID())
                        + " at time: " + Clock.GetCurrentTime());

                SetTextColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout("\n" + GetNameOfEntity(son.ID()) + ": I'll go somewhere else..");
                son.SetFollowing(false);     
            }

            return true;

        }//end switch

        return false;
    }

}