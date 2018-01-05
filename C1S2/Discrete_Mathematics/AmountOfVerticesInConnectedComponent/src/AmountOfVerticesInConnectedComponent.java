/**
 * Created by roman on 6/4/17.
 */

import java.io.*;
import java.util.Scanner;

import java.util.Queue;
import java.util.LinkedList;

public class AmountOfVerticesInConnectedComponent
{
    int BFS(int V, int startV) // returns amount of edges in connected component
    {
        final int INF = (int) 1E9;
        int[] minDist = new int[V]; // minimal distance from startVertex
        Queue<Integer> queue = new LinkedList<>();

        for (int v = 0; v < V; v++) // v is for vertex
        {
            minDist[v] = INF;
        }

        minDist[startV] = 0;
        queue.add(startV);

        int CCV = 1; // amount of vertices in connected component, which contains startVertex

        while (!queue.isEmpty())
        {
            int currentV = queue.poll();

            for (int v = 0; v < V; v++) // v is for vertex
            {
                if (graph[currentV][v] == 1 && minDist[v] == INF)
                {
                    minDist[v] = minDist[currentV] + 1;
                    queue.add(v);
                    CCV++;
                }
            }
        }

        return CCV;
    }

    public static void main(String[] args)
    {
        AmountOfVerticesInConnectedComponent p = new AmountOfVerticesInConnectedComponent();

        long startTime = System.currentTimeMillis();
        p.run();
        long endTime = System.currentTimeMillis();

        p.out.flush();

        System.out.println("Runtime: " + (endTime - startTime) + " ms");
    }

    Scanner in;
    PrintWriter out = new PrintWriter(System.out);

    int[][] graph; // save time on passing to function

    int run() // returns error status
    {
        for (int i = 1; i <= 6; i++) // test numeration
        {
            try
            {
                in = new Scanner(new File("Tests/test" + i + ".in"));
            }
            catch (FileNotFoundException ex)
            {
                out.println("Input test file " + i + " not found.\nExiting...");

                return 1;
            }

            int V = in.nextInt(); // amount of vertices
            int E = in.nextInt(); // amount of edges
            int startV = in.nextInt();

            graph = new int[V][V];

            for (int e = 0; e < E; e++) // e is for edge
            {
                int fromV = in.nextInt();
                int toV = in.nextInt();

                graph[fromV][toV] = 1;
                graph[toV][fromV] = 1;
            }

            int result = BFS(V, startV);

            try
            {
                in = new Scanner(new File("Tests/test" + i + ".out"));
            }
            catch (FileNotFoundException ex)
            {
                out.println("Output test file " + i + " not found.\nResult: " + result + "\nExiting...");

                return 1;
            }

            int expectedResult = in.nextInt();

            out.print("Test " + i + ": ");

            if (result == expectedResult)
            {
                out.println("OK, Result = " + result);
            }
            else
            {
                out.println("Wrong answer, Result = " + result + ", Expected = " + expectedResult);
            }
        }

        return 0;
    }
}
