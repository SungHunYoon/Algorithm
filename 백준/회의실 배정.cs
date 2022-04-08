using System;
using System.Collections;

public class Comparer : IComparer
{
    int key;
    public Comparer( int key )
    {
        this.key = key;
    }

    public int Compare( object x, object y )
    {
        Time tX = x as Time;
        Time tY = y as Time;

        if( tX == null || tY == null )
        {
            throw new ApplicationException( "Error" );
        }

        if( key == 0 )
        {
            return tX.StartTime.CompareTo( tY.StartTime );
        }
        else
        {
            return tX.EndTime.CompareTo( tY.EndTime );
        }
    }
}
public class Time
{
    public int StartTime{ get; set; }
    public int EndTime{ get; set; }
    public Time( int StartTime, int EndTime )
    {
        this.StartTime = StartTime;
        this.EndTime = EndTime;
    }

    public override string ToString()
    {
        return string.Format( "{0} {1}", StartTime, EndTime );
    }
}
public class Program
{
    static void Main( string[] args )
    {
        int nCount = int.Parse( Console.ReadLine() );

        if( nCount > 100000 ||
            nCount < 1 )
        {
            return;
        }

        Time[] time = new Time[ nCount ];
        for( int i = 0; i < nCount; i++ )
        {
            string[] strInput = Console.ReadLine().Split();
            time[ i ] = new Time( int.Parse( strInput[ 0 ] ), int.Parse( strInput[ 1 ] ) );
        }

        Array.Sort( time, new Comparer( 0 ) );
        Array.Sort( time, new Comparer( 1 ) );

        int LastEndTime = 0;
        int Count = 0;
        for ( int i = 0; i < nCount; i++ )
        {
            if( LastEndTime <= time[ i ].StartTime )
            {
                LastEndTime = time[ i ].EndTime;
                Count++;
            }
        }

        Console.WriteLine( Count );
        //Console.Read();
    }
}
